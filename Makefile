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
CFLAGS := -ms -0 -d0 -oa -ob -os -s -zl -i$(WATCOM)/h -isrc

# Linker script for DOS MZ output
# system dos   = produce MS-DOS MZ executable
# Runtime objects for 32-bit arithmetic helpers and stack check (__U4M, __I4M, __U4D, __I4D, __STK)
# Extracted from clibs.lib to avoid pulling in the C startup expecting main()
RTDIR   := tools/runtime
RTOBJS  := $(RTDIR)/i4m.o $(RTDIR)/i4d.o

LDFLAGS := system dos

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

# Link step
$(TARGET): $(ALL_OBJS) $(RTOBJS)
	@echo "[LINK] $@"
	$(WLINK) $(LDFLAGS) name $@ file { $(ALL_OBJS) $(RTOBJS) }

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
