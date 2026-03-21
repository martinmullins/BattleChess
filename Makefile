# Battle Chess Build System
# Targets 16-bit x86 Real Mode MS-DOS (produces CHESS.EXE)
#
# Requires Open Watcom V2 (set WATCOM env var to install root)
# e.g. export WATCOM=/opt/watcom
#
# Usage:
#   make          - build CHESS.EXE
#   make clean    - remove build artifacts
#   make verify   - compare built EXE against original binary

WATCOM     ?= /opt/watcom
export WATCOM
BINDIR     := $(WATCOM)/binl

WCC        := $(BINDIR)/wcc
WASM       := $(BINDIR)/wasm
WLINK      := $(BINDIR)/wlink

# Compiler flags for 16-bit real-mode DOS (small memory model)
# -ms  = small memory model (CS=DS=SS, one 64K code + one 64K data segment)
# -0   = target 8086/8088 instructions
# -d0  = no debug info (use -d2 for debug build)
# -oa  = relax aliasing constraints
# -ob  = branch prediction
# -os  = favor code size over speed
# Note: -oe (inlining) omitted - triggers E1119 ICE in wcc for this source
# -s   = no stack overflow checking (avoids __STK runtime dependency)
# -zl  = suppress default library references (we control the link step)
# -i   = include path
# -wcd102 = suppress W102 type mismatch (Ghidra decompiler uses int/ptr coercions
#           throughout; all types are 16-bit in DOS small model so these are benign)
# -wcd104 = suppress W104 inconsistent indirection (Ghidra emits local_4=&local_4
#           self-referential stack pointer patterns for linked list nodes)
# -wcd124 = suppress W124 comparison always 0/1 (Ghidra uses byte/undefined1 for
#           what should be signed char; byte==-95 is always false but intended)
CFLAGS := -ms -0 -d0 -oa -ob -oi -os -s -zl -i$(WATCOM)/h -isrc -wcd102 -wcd104 -wcd124

# Linker script for DOS MZ output
# format dos   = produce MS-DOS MZ executable
# (use 'format dos' directly rather than 'system dos' to avoid W1107 on this
#  Linux Watcom build where wlink.lnk has a caret in the dos system entry)
# Runtime objects for 32-bit arithmetic helpers and stack check (__U4M, __I4M, __U4D, __I4D, __STK)
# Extracted from clibs.lib to avoid pulling in the C startup expecting main()
RTDIR   := tools/runtime
RTOBJS  := $(RTDIR)/i4m.o $(RTDIR)/i4d.o

# entry_ = entry point (void entry() in chess.c, Ghidra decompilation of 243e:0001)
# mindata = min extra data paragraphs for overlay buffers (original uses 22083)
# Note: wlink 'format dos' does not support option mindata; patch MZ header post-link if needed
LDFLAGS := format dos option start=entry_

SRCDIR  := src
OBJDIR  := build
TARGET  := CHESS.EXE
ORIGINAL := CHESS.EXE.orig

# Source files - main decompiled C split into compilation units
CSRCS   := $(wildcard $(SRCDIR)/*.c)
OBJS    := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.obj,$(CSRCS))

# NASM assembly sources (hand-crafted or extracted stubs)
ASRCS   := $(wildcard $(SRCDIR)/*.asm)
AOBJS   := $(patsubst $(SRCDIR)/%.asm,$(OBJDIR)/%.obj,$(ASRCS))

ALL_OBJS := $(OBJS) $(AOBJS)

.PHONY: all clean verify setup

all: $(TARGET)

# MZ header min_alloc field (bytes 0x0A-0x0B)
# wlink 'format dos' does not expose this field; patch post-link with python
# Original CHESS.EXE uses 22083 paragraphs (~353KB) for overlay buffer allocation
MZ_MINALLOC := 22083

# Link step
$(TARGET): $(ALL_OBJS) $(RTOBJS)
	@echo "[LINK] $@"
	$(WLINK) $(LDFLAGS) name $@ file { $(ALL_OBJS) $(RTOBJS) }
	@python3 -c "import struct,sys; \
	    f=open('$@','r+b'); \
	    f.seek(10); old=struct.unpack('<H',f.read(2))[0]; \
	    f.seek(10); f.write(struct.pack('<H',$(MZ_MINALLOC))); f.close(); \
	    print('[PATCH] MZ min_alloc: {} -> $(MZ_MINALLOC)'.format(old))"

# C compilation (16-bit wcc)
$(OBJDIR)/%.obj: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "[CC]   $<"
	$(WCC) $(CFLAGS) -fo=$@ $<

# NASM assembly
$(OBJDIR)/%.obj: $(SRCDIR)/%.asm | $(OBJDIR)
	@echo "[ASM]  $<"
	nasm -f obj -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

# Compare against original binary (byte-for-byte)
verify: $(TARGET)
	@if [ -f $(ORIGINAL) ]; then \
		if cmp -s $(TARGET) $(ORIGINAL); then \
			echo "SUCCESS: $(TARGET) matches original binary"; \
		else \
			echo "MISMATCH: $(TARGET) differs from original"; \
			echo "Size of built:    $$(wc -c < $(TARGET)) bytes"; \
			echo "Size of original: $$(wc -c < $(ORIGINAL)) bytes"; \
		fi \
	else \
		echo "No $(ORIGINAL) found for comparison. Copy original CHESS.EXE to $(ORIGINAL) first."; \
	fi

# Install toolchain (run once)
setup:
	@bash tools/setup.sh
