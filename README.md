# 🧩 **BSQ - 42 Paris Piscine**

> _Fast C CLI that reads maps from files or stdin, computes the largest empty square (dynamic programming), and prints them back with the largest empty square._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: Optimized after Piscine](https://img.shields.io/badge/status-Optimized%20after%20Piscine-darkgreen)]()

---

## 🪄 Highlights

- **_Dynamic growth_ I/O buffer**: reduces the number of `read` system calls  
- **Unified parsing and solving**: single-pass computation  
- **Flat memory layouts**: reduce data access time, memory usage, and copy overhead  
- **Flat _dynamic programming_ table**: reduces computation time  
- **In-place editing of the original map**: avoids full map copies and checks  
- **One-time output**: avoids multiple `write` system calls  
- **Integrated benchmark** (10 iterations) with the `--bench` flag as the first argument

---

## 🚀 Performance
- A 10 000×10 000 map is processed in **~190 ms**

> _Measured on macOS / Apple M4 / `<time.h>` / `clock_gettime()`_
> 
> _`stdout` redirected to `/dev/null` to eliminate potential shell or terminal I/O bottlenecks_

| Version | Description | 10k×10k |
|:----------|:-------------|------------------------------:|
| **v1.1.0** | **Baseline** (42 Paris Piscine version) | ~37 000 ms |
| **v1.2.0** | **Output optimization**<br>→ Added output buffer (`char **`) | ~5 800 ms |
| **v1.3.0** | **Output optimization**<br>→ Switched output to flat buffer (`char *`) | ~5 600 ms |
| **v1.4.0** | **General optimization**<br>→ Removed initialization loops | ~5 400 ms |
| **v2.0.0** | **Major refactor**<br>→ Simplified data structures<br>→ Unified parsing and solving<br>→ Optimized flat I/O buffers<br>→ Flattened map and DP arrays | ~320 ms |
| **v2.1.0** | **Output optimization**<br>→ In-place map editing (no full copy)<br>→ Only updates the required characters inside the map | ~250 ms |
| **v2.1.1** | **QoL update**<br>→ Integrated benchmark mode (10 iterations) | ~200 ms |
| **v2.2.0** | **Input optimization**<br>→ Reworked `str_grow()` to dereference pointer **once** before the loop<br>→ Reduced redundant memory accesses during buffer reallocation | ~190 ms |
| **v2.2.1** | **Input optimization**<br>→ Switched to native C types during file read operations<br>→ Implemented in-place reading to remove buffer duplication and reduce latency | ~180 ms |

---

## 🎓 **Context**

The **BSQ (Biggest Square)** is the final algorithmic project of the **42 Paris Piscine**.  
Its goal is to parse a text-based map - from file(s) or stdin - and compute the largest possible empty square, following the official 42 C **Norm v4**.

This project is a deep dive into:
- **Dynamic programming** for 2D optimization problems  
- **Memory management and I/O efficiency**  
- **Strict compliance** with the **42 Norm**

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
if (map[row][col] == empty)
	dp[row][col] = 1 + min(dp[row-1][col], dp[row][col-1], dp[row-1][col-1]);
else
	dp[row][col] = 0;
```
3. The largest value found indicates the **size and position** of the biggest square.

---

## 🗂️ **Repository structure**

```
bsq/
├── README.md				# This README file
├── bsq.subject.en.pdf		# Official 42 subject (English)
├── Makefile				# Build rules and compiler settings (Norm-compliant)
├── includes/				# Header files with type definitions and prototypes
├── srcs/					# Source files (C code)
│   ├── main.c				# Entry point
│   ├── objects/
│   │   ├── run.c			# Constructor and free function for run struct
│   │   └── string.c		# String manipulation tools
│   ├── read.c				# Reads content from filepath
│   ├── parse.c				# Parses rules then simultaneously parses and solves the map
│   ├── result.c			# Prints result
│   ├── time.c				# Utilities for benchmark mode
│   └── utils.c				# Utility functions (is_printable and fast_atoi_n)
└── tests/					# Sample maps and performance benchmarks
```

---

## 🧰 **Build and Run**

### Compilation
```bash
# Compiles the standard binary
make

# Compiles the fast binary
make fast

# Compiles the (sometimes) faster binary
make sfast
```

### Run with one or more files
```bash
./bsq file_path_1 file_path_2 ... file_path_n
```

### Run with stdin
⚠️ This feature has been removed from v2.0.0.
Coming back soon...
```bash
cat tests/basic_test | ./bsq
```

### Run automatic benchmark
- Automatically runs 10 iterations with the file given as the second argument
- Displays (on `stderr`) the timings of each run and their average
> _Bench output is printed to `stderr`_
> 
> _Redirect `stdout` to `/dev/null` to eliminate potential shell or terminal I/O bottlenecks_
```bash
./bsq --bench file_path > /dev/null
```

### Clean build files
```bash
# Only clean objects
make clean

# Clean objects and binary
make fclean
```

---

> _“Think out of the square — then fill it.”_ 🧠
