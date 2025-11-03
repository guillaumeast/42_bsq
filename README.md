# 🧩 **BSQ - 42 Paris Piscine**

> _Fast C CLI that reads maps from files or `stdin`, computes the largest empty square (dynamic programming), and prints them back with the largest empty square._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: Optimized after Piscine](https://img.shields.io/badge/status-Optimized%20after%20Piscine-darkgreen)]()

---

## 🪄 Highlights

- **_Dynamic growth_ I/O buffer**: reduces the number of `read` system calls  
- **Unified parsing and solving**: single-pass computation combining map validation and `dp` update 
- **Flat memory layouts**: reduce data access time, memory usage, and copy overhead  
- **Single-row array _dynamic programming_ layout**: improves memory footprint and L1 cache locality.
- **In-place editing of the original map**: avoids full map copies and checks  
- **One-time output**: avoids multiple `write` system calls  
- **Integrated tests** with the `make test` command
- **Integrated benchmark** (100 iterations) with the `make bench` command

---

## 🎓 **Context**

The **BSQ (Biggest Square)** is the final algorithmic project of the **42 Paris Piscine**.  
Its goal is to parse a text-based map - from file(s) or stdin - and compute the largest possible empty square, following the official 42 C **Norm v4**.

This project is a deep dive into:
- **_Dynamic programming_** for **2D optimization problems**  
- **Execution time optimization** using **low-level CPU profiling** and **micro-optimization techniques**
- **Memory management and I/O efficiency**  
- **Compliance** with the **42 Norm**

> ⚠️ **Note on 42 Norm deviations:**  
> For the purpose of real-world performance analysis, this project intentionally:  
> - Uses **compiler optimization flags** (normally forbidden by the `42 C Norm`)  
> - Implements a **basic `stdin` handler** only, without on-the-fly parsing or flooding edge case handling  
>
> These choices were made to focus exclusively on **execution time optimization** when parsing from files —  
> since real-time `stdin` parsing requires more granular (and thus slower) parsing steps,  
> which would conflict with the project's main optimization objective.

---

## ⚙️ **Objective**

- Read maps from one or more **files**, or directly from **stdin**  
- Detect invalid or corrupted maps (missing lines, inconsistent width, invalid characters, etc.)  
- Efficiently compute the **largest empty square**, even on large maps (e.g. 10k×10k)  
- Output the map with the square marked using the `filled` character

---

## 🧩 **Algorithm**

The program implements a **dynamic programming** approach:
1. Each cell represents the size of the largest square ending at that point.  
2. The recurrence relation:
```c
if (map[row][col] == EMPTY)
	dp[row][col] = 1 + min(dp[row-1][col], dp[row][col-1], dp[row-1][col-1]);
else
	dp[row][col] = 0;
```
3. The largest value found indicates the **size and position** of the biggest square.

> _For performance reasons, the first row and the first column of each row are computed by dedicated functions: `parse_row_0()` and `parse_col_0()`._
>
> _Additionally, the `dp` is implemented using a single-row array and a temporary value (representing the up-left cell: `dp[row-1][col-1]`)._
>
> _The 2D relation above is shown for clarity, as the actual implementation uses a 1D array for better memory locality._

> _For experimental branchless versions of the DP computation, see [branchless_comparison.md](branchless_comparison.md)._
>
> _This file documents the _bitmask-based_ and _XOR-based_ approaches I tested to minimize _branch mispredictions_, and explains why it didn't produce the expected results._

---

## 🚀 Performance
- A 10,000×10,000 map is processed in less than **80 ms**

> _Measured on macOS (Apple M4) using `<time.h>` / `clock_gettime()`_
> 
> _`stdout` redirected to `/dev/null` to eliminate potential shell or terminal I/O bottlenecks_

| Version | Description | 10k×10k (ms) |
|:----------|:-------------|------------------------------:|
| [**v1.1.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v1.0.0) | **Baseline** (42 Paris Piscine version) | ~37,000 ms |
| **v1.2.0** | **Output optimization**<br>→ Added output buffer (`char **`) | ~3,800 ms |
| **v1.3.0** | **Output optimization**<br>→ Switched output to flat buffer (`char *`) | ~3,600 ms |
| **v1.4.0** | **General optimization**<br>→ Removed initialization loops | ~3,400 ms |
| [**v2.0.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v2.0.0) | **Major refactor**<br>→ Simplified data structures<br>→ Unified parsing and solving<br>→ Optimized flat I/O buffers<br>→ Flattened map and DP arrays | ~320 ms |
| [**v2.1.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v2.1.0) | **Output optimization**<br>→ In-place map editing (no full copy)<br>→ Only updates the required characters inside the map | ~250 ms |
| [**v2.1.1**](https://github.com/guillaumeast/42_bsq/releases/tag/v2.1.1) | **QoL update**<br>→ Integrated benchmark mode (10 iterations) | ~200 ms |
| [**v2.2.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v2.2.0) | **Input optimization**<br>→ Reworked `str_grow()` to dereference pointer **once** before the loop<br>→ Reduced redundant memory accesses during buffer reallocation | ~190 ms |
| **v2.2.1** | **Input optimization**<br>→ Switched to native C types during file read operations<br>→ Implemented in-place reading to remove buffer duplication and reduce latency | ~180 ms |
| [**v2.3.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v2.3.0) | **Parse optimization**<br>→ Optimized DP minimum computation to reduce branch-misses | ~140 ms |
| [**v2.4.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v2.4.0) | **Parse optimization**<br>→ Reordered parser condition checks to reduce branch mispredictions<br>→ Implemented precomputation of all possible values<br>→ Minimized dereferencing in hot loops<br>→ Increased integrated benchmark from 10 to 100 iterations | ~100 ms |
| **v2.5.0** | **Code cleanup & build optimization**<br>→ Removed unused fields, return values and redundant casts<br>→ Inlined hot functions<br>→ Added `-fomit-frame-pointer` and `-fno-stack-protector` flags<br>→ Introduced optional PGO build (`make sfast`) | ~100 ms |
| [**v3.0.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v3.0.0) | **Code cleanup, tests implementation, bug fixes, and _branchless_ comparison investigation**<br>→ Added `make test` and `make bench` commands<br>→ Fixed multiple issues<br>→ See [CHANGELOG.md](CHANGELOG.md) for more details | ~100 ms |
| [**v3.1.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v3.1.0) | **Parse optimization**<br>→ Implemented `parse_col_0()` to speed up parsing and solving of the first col of each row | ~87 ms |
| [**v3.2.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v3.2.0) | **Parse optimization**<br>→ Implemented **single-row array `dp`** for faster updates | ~77 ms |
| **v3.2.1** | **Input optimization**<br>→ Improved (only for no-opt builds) map reading logic with a **Adaptive I/O buffer**: grows dynamically to read headers, then resizes to load the full map in one go<br>→ > This version has **not** been released because execution time was higher than expected | ~200 ms |
| [**v4.0.0**](https://github.com/guillaumeast/42_bsq/releases/tag/v4.0.0) | **Reimplemented `stdin` parsing**<br>→ No on-the-fly parsing — thus no handling of potential `stdin` flooding edge cases<br>→ Real-time `stdin` parsing would require more granular parsing steps, which would reduce overall performance and conflict with the primary optimization goal | ~77 ms |

---

## 🗂️ **Repository structure**

```
bsq/
├── README.md				# This README file
├── bsq.subject.en.pdf		# Official 42 subject (English)
├── Makefile				# Build rules and compiler settings
├── includes/				# Header files with type definitions and prototypes
├── srcs/					# Source files (C code)
│   ├── main.c				# Entry point
│   ├── objects/			# Constructor and destructor functions for custom structs
│   ├── utils/				# Utilities
│   ├── read.c				# Reads content from filepath/stdin
│   ├── parse_rules.c		# Parses rules
│   ├── parse_map.c			# Simultaneously parses and solves the map
│   └── result.c			# Prints result
└── tests/					# Sample maps and performance benchmarks
```

---

## 🧰 **Build and Run**

### Compilation
```bash
# Compile the standard binary
make

# Compile the optimized (fast) binary
make fast

# Compile, run the binary to collect profiling data, and then recompile it with PGO optimizations
make sfast
```

### Run with one or more files
```bash
./bsq file_path_1 file_path_2 ... file_path_n
```

### Run with stdin
Coming back soon...
```bash
cat tests/basic_test | ./bsq
```

### Run tests
```bash
make test
```

### Run automatic benchmark
- Automatically runs 100 iterations with 10kx10k map as input
- Displays average timings to `stderr`
> _`stdout` is redirected to `/dev/null` to eliminate potential shell or terminal I/O bottlenecks_
```bash
make bench
```

### Clean build files
```bash
# Only clean objects and tests results
make clean

# Clean objects, tests results and binary
make fclean
```

---

> _“Think out of the square — then fill it.”_ 🧠
