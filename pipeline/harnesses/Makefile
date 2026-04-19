# Makefile — Build all LibFuzzer harnesses (Tier 1, 2, 3)
#
# Prerequisites for `make all` (fuzz targets):
#   sudo apt install libclang-rt-18-dev
#
# Prerequisites for `make check` (logic-only, no fuzzer runtime needed):
#   clang (any version)
#
# Targets:
#   make check    — compile all harnesses in standalone mode (no libFuzzer runtime)
#   make all      — build full LibFuzzer binaries (requires libclang-rt-18-dev)
#   make fuzz-all — run all harnesses for 30 s each (requires `make all`)
#   make clean    — remove build artefacts

CC      := clang
CFLAGS_FUZZ := -O1 -g -std=c11 \
               -fsanitize=fuzzer,address,undefined \
               -fno-omit-frame-pointer \
               -Wall -Wno-unused-function
CFLAGS_CHECK := -O1 -g -std=c11 \
                -fno-omit-frame-pointer \
                -DSTANDALONE_TEST \
                -Wall -Wno-unused-function
IMPL    := tier1_impl.c

TIER1_TARGETS := \
    fuzz_min_int \
    fuzz_max_int \
    fuzz_abs_int \
    fuzz_is_odd \
    fuzz_is_printable \
    fuzz_coord_to_zone \
    fuzz_offset_sentinel \
    fuzz_div32

TIER2_TARGETS := \
    fuzz_clear_anim_flag \
    fuzz_set_text_cursor \
    fuzz_handle_nav_key \
    fuzz_pack_char_cell \
    fuzz_snapshot_viewport \
    fuzz_push_viewport

TIER3_TARGETS := \
    fuzz_save_game_regs \
    fuzz_restore_game_regs \
    fuzz_clamp_text_size

TARGETS := $(TIER1_TARGETS) $(TIER2_TARGETS) $(TIER3_TARGETS)

TIER1_CHECK := $(addprefix check_, $(subst fuzz_,,$(TIER1_TARGETS)))
TIER2_CHECK := $(addprefix check_, $(subst fuzz_,,$(TIER2_TARGETS)))
TIER3_CHECK := $(addprefix check_, $(subst fuzz_,,$(TIER3_TARGETS)))
CHECK_BINS  := $(TIER1_CHECK) $(TIER2_CHECK) $(TIER3_CHECK)

.PHONY: all check fuzz-all clean

# --- Full LibFuzzer build (requires libclang-rt-18-dev) ---
all: $(TARGETS)

IMPL2   := tier2_impl.c
IMPL3   := tier3_impl.c
SEG     := seg_storage.c

fuzz_min_int fuzz_max_int fuzz_abs_int fuzz_is_odd fuzz_is_printable \
fuzz_coord_to_zone fuzz_offset_sentinel fuzz_div32: %: %.c $(IMPL) tier1_impl.h ghidra_compat.h
	$(CC) $(CFLAGS_FUZZ) -o $@ $< $(IMPL)

fuzz_clear_anim_flag fuzz_set_text_cursor fuzz_handle_nav_key \
fuzz_pack_char_cell fuzz_snapshot_viewport fuzz_push_viewport: %: %.c $(IMPL2) tier2_impl.h tier2_seg.h ghidra_compat.h
	$(CC) $(CFLAGS_FUZZ) -o $@ $< $(IMPL2)

# Tier 3 harnesses link seg_storage.c (provides g_chess_seg) + tier3_impl.c
fuzz_save_game_regs fuzz_restore_game_regs fuzz_clamp_text_size: %: %.c $(IMPL3) $(SEG) tier3_impl.h tier2_seg.h ghidra_compat.h
	$(CC) $(CFLAGS_FUZZ) -o $@ $< $(IMPL3) $(SEG)

# --- Standalone logic check (no libFuzzer runtime needed) ---
check: $(CHECK_BINS)
	@echo "=== All check builds passed ==="
	@for b in $(CHECK_BINS); do echo "  Running $$b..."; ./$$b && echo "  OK"; done

$(TIER1_CHECK): check_%: fuzz_%.c $(IMPL) tier1_impl.h ghidra_compat.h standalone_main.h
	$(CC) $(CFLAGS_CHECK) -c -o impl_$@.o $(IMPL)
	$(CC) $(CFLAGS_CHECK) -include standalone_main.h -c -o harness_$@.o $<
	$(CC) $(CFLAGS_CHECK) -o $@ harness_$@.o impl_$@.o
	@rm -f impl_$@.o harness_$@.o

$(TIER2_CHECK): check_%: fuzz_%.c $(IMPL2) tier2_impl.h tier2_seg.h ghidra_compat.h standalone_main.h
	$(CC) $(CFLAGS_CHECK) -c -o impl_$@.o $(IMPL2)
	$(CC) $(CFLAGS_CHECK) -include standalone_main.h -c -o harness_$@.o $<
	$(CC) $(CFLAGS_CHECK) -o $@ harness_$@.o impl_$@.o
	@rm -f impl_$@.o harness_$@.o

$(TIER3_CHECK): check_%: fuzz_%.c $(IMPL3) $(SEG) tier3_impl.h tier2_seg.h ghidra_compat.h standalone_main.h
	$(CC) $(CFLAGS_CHECK) -c -o impl_$@.o $(IMPL3)
	$(CC) $(CFLAGS_CHECK) -c -o seg_$@.o   $(SEG)
	$(CC) $(CFLAGS_CHECK) -include standalone_main.h -c -o harness_$@.o $<
	$(CC) $(CFLAGS_CHECK) -o $@ harness_$@.o impl_$@.o seg_$@.o
	@rm -f impl_$@.o seg_$@.o harness_$@.o

# --- Smoke fuzz run: 30 s per target ---
fuzz-all: all
	@for t in $(TARGETS); do \
	    name=$$(echo $$t | sed 's/fuzz_//'); \
	    echo "=== $$t (30s) ==="; \
	    ./$$t seeds/$$name/ -max_total_time=30 -print_final_stats=1 2>&1; \
	done

clean:
	rm -f $(TARGETS) $(CHECK_BINS)
