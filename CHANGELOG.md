## [3.0.0] - ~100 ms on 10,000 x 10,000 maps

### Optimizations

- Converted full size `int *` array into two little arrays of size row_len to optimize cache usage
- Optimized `if` statements order
- Removed `run_set_width()` and added `parse_row_0()` to avoid double read of row 0
- Added (commented) _bitmask-based_ and _xor-based_ versions of the original _if-based_ `solve_cell()`
	- The goal was to reduce branch mispredictions using a _branchless_ comparison method
	- All three versions compile down to a **single `csel` instruction** with `-O1` or higher
	- _if-based_ and _xor-based_ versions run in **similar time** without optimization flags
	- _bitmask-based_ version runs **about 35 % slower** without optimization (due to the extra `mask` variable)
	- For **code readability**, the _if-based_ version remains the one used in the project
	- Added `bit_masks.md` to document the _bitmask-based_ and _xor-based_ approaches

### Bug fixes

- Fix multiple incorrect rules, maps and file path handling
-Changed `malloc(sizeof(type))` to `malloc(sizeof *p)` to prevent type mismatch errors and simplify code maintainability
- Fix memory leaks (`run->map` was leaked in some `map error` cases)

### Tests and benchmark mode updates

- Added `make test` command to automatically run tests
- Added `make bench` rule to `Makefile` to make bench running easier
	- Automatically runs `make test` before starting the bench
- Updated command used to run benchmark to improve **timings accuracy**
	- Old command = `./bsq --bench tests/test_10000 > /dev/null`
	- New command = `sudo caffeinate nice -n -20 ./bsq --bench tests/test_10000 > /dev/null`
- Removed **individual** run timings for a more readable output
- Added `CLOCK_BENCH` conditionnal definition to `bench.h` to improve **timings accuracy**
	- Changed `CLOCK_MONOTONIC` to `CLOCK_UPTIME_RAW` for macOS
	- Changed `CLOCK_MONOTONIC` to `CLOCK_MONOTONIC_RAW` for Linux

### Refactorizations

- Moved the `BUFFER_SIZE` definition from `types.h` to `read.h`
- Moved `RULES_MIN_LEN` and `RULES_CHARSET_LEN` definitions from `types.h` to `parse_rules.h`
- Added a `VERSION` definition to `bsq.h`
- Split `parse.c` into `parse_rules.c` and `parse_map.c` for _42 norm_ compliance (5 functions max per file)

---

## [2.5.0] - ~100 ms on 10,000 x 10,000 maps
- Removed all unnecessary return values from functions
- Removed the unused `cap` attribute from `t_str`
- Changed `bsq.size` from `size_t` to `int` to avoid casts
- Changed the return type of `ft_fast_atoi_n` from `int` to `size_t` to avoid casts
- Inlined `set_min()` into `solve_cell()`
- Removed the useless `-ffast-math` flag and the associated `make sfast` rule
- Added the `-fomit-frame-pointer` `-fno-stack-protector` flags to the `make fast` rule
- Added a `make sfast` rule to enable _PGO_ optimisation

---

## [2.4.2] - ~100 ms on 10,000 x 10,000 maps
- Refactored main.c and bench.c
- Fix multiple files handling issues

---

## [2.4.1] - ~100 ms on 10,000 x 10,000 maps
- Avoid useless last buffer grow
- Refactored main.c, run.c, parse.c and bench.c
- Fix multiple freeing of not allocated pointers
- Fix multiple files handling issues

---

## [2.4.0] - ~100 ms on 10,000 x 10,000 maps
- Reordered parser condition checks to reduce branch mispredictions
- Implemented precomputation of all possible values
- Minimized dereferencing in hot loops
- Increased integrated benchmark from 10 to 100 iterations

---

## [2.3.0] - ~140 ms on 10 000 x 10 000 maps
- Optimized **DP minimum computation** to reduce miss-branches

---

## [2.2.1] - ~180 ms on 10 000 x 10 000 maps
- Switched to native C types during file read operations
- Implemented in-place reading to remove buffer duplication and reduce latency

---

## [2.2.0] - ~190 ms on 10 000 x 10 000 maps
- Reworked `str_grow()` to dereference pointer **once** before loop instead of at each iteration  
- Reduced redundant memory accesses during buffer reallocation  

---

## [2.1.1] - ~200 ms on 10 000 x 10 000 maps
- Added **integrated benchmark mode**
- Added **average** timings to the displayed performance metrics

### Important benchmark modifications
- The benchmark is now run with `stdout` redirected to `/dev/null` instead of a file to eliminate potential shell or terminal I/O bottlenecks  
- This change alone results in a **~50 ms improvement**

---

## [2.1.0] - ~250 ms on 10 000 x 10 000 maps
- **Modifies the initial map** (`char *`) instead of creating a new one for output
- Avoids full map copies — **only updates required characters**

---

## [2.0.0] - ~320 ms on 10 000 x 10 000 maps
- **Unified parsing and solving** logic (single-pass DP computation)
- Optimized **dynamic growth** for read buffer
- Optimized **flat memory layout** for map and DP arrays
- Removed all `ft_split()`, `ft_strlen()`, `ft_strncat()`, `ft_strndup()` calls
- **Simplified data structures** of `t_run`
- New `t_str` **structure** for efficient dynamic strings
- Added **detailed performance metrics** (in ms)
- Added **ASCII box display** for runtime statistics

---

## [1.4.0] - ~3 400 ms on 10 000 x 10 000 maps
- Removed table/output initialisations
- Used height/width instead of checking map

---

## [1.3.0] - ~3 600 ms on 10 000 x 10 000 maps
- Converted output from `char **` to `char *`

---

## [1.2.0] - ~3 800 ms on 10 000 x 10 000 maps
- Added output buffer `char **`

---

## [1.1.0] - ~37 000 ms on 10 000 x 10 000 maps
- Initial version developed during the 42 Paris Piscine
- Implemented naive I/O and line-by-line parsing - O(n²)

---

> _“Think out of the square — then fill it.”_ 🧠
