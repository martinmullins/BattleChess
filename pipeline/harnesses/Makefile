# Makefile — Build all Tier 1 LibFuzzer harnesses
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

TARGETS := \
    fuzz_min_int \
    fuzz_max_int \
    fuzz_abs_int \
    fuzz_is_odd \
    fuzz_is_printable \
    fuzz_coord_to_zone \
    fuzz_offset_sentinel \
    fuzz_div32

CHECK_BINS := $(addprefix check_, $(subst fuzz_,,$(TARGETS)))

.PHONY: all check fuzz-all clean

# --- Full LibFuzzer build (requires libclang-rt-18-dev) ---
all: $(TARGETS)

fuzz_%: fuzz_%.c $(IMPL) tier1_impl.h ghidra_compat.h
	$(CC) $(CFLAGS_FUZZ) -o $@ $< $(IMPL)

# --- Standalone logic check (no libFuzzer runtime needed) ---
check: $(CHECK_BINS)
	@echo "=== All check builds passed ==="
	@for b in $(CHECK_BINS); do echo "  Running $$b..."; ./$$b && echo "  OK"; done

check_%: fuzz_%.c $(IMPL) tier1_impl.h ghidra_compat.h standalone_main.h
	$(CC) $(CFLAGS_CHECK) -c -o impl_$@.o $(IMPL)
	$(CC) $(CFLAGS_CHECK) -include standalone_main.h -c -o harness_$@.o $<
	$(CC) $(CFLAGS_CHECK) -o $@ harness_$@.o impl_$@.o
	@rm -f impl_$@.o harness_$@.o

# --- Smoke fuzz run: 30 s per target ---
fuzz-all: all
	@for t in $(TARGETS); do \
	    name=$$(echo $$t | sed 's/fuzz_//'); \
	    echo "=== $$t (30s) ==="; \
	    ./$$t seeds/$$name/ -max_total_time=30 -print_final_stats=1 2>&1; \
	done

clean:
	rm -f $(TARGETS) $(CHECK_BINS)
