# 🧩 **BSQ - 42 Paris Piscine**

> _Fast C CLI that reads maps from files or stdin, computes the largest empty square (dynamic programming), and prints them back with the largest empty square._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: v2.0.0 - Optimized after Piscine](https://img.shields.io/badge/status-Optimized%20after%20Piscine-darkgreen)]()

---

## 🪄 v2.0.0 Highlights

- Unified parsing and solving logic (**single-pass dynamic programming**)
- Fully rewritten buffered I/O using raw `read()` with **dynamic growth**
- New `t_str` structure for efficient string concatenation without `strlen()` or other expensive functions
- Simplified **data structures**
- Added ASCII **runtime stats** box with per-phase timing

---

## 🚀 v2.0.0 Performance
- 10 000×10 000 map processed in **~300 ms** (vs ~5 400 ms in v1.4.0)
- **~30 % lower memory usage** thanks to flattened arrays

| Version | Description | Real Time (10k×10k map) |
|----------|-------------|------------------------------|
| **v1.1.0 (Piscine)** | Baseline (string join, naïve I/O) | ~37 s |
| **v1.2.0** | Added output buffer (`char **`) | ~5.8 s |
| **v1.3.0** | Switched output to flat buffer (`char *`) | ~5.6 s |
| **v1.4.0** | Removed initialization loops | ~5.4 s |
| **v2.0.0** | Simplified data structures, unified parsing and solving, optimized flat I/O buffers, flattened map and DP arrays | 🚀 **~300 ms** |

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
if (map[y][x] == empty)
	res[y][x] = 1 + min(res[y-1][x], res[y][x-1], res[y-1][x-1]);
else
	res[y][x] = 0;
```
3. The largest value found indicates the **size and position** of the biggest square.

This implementation uses:
- **O(n) Buffered I/O** to minimize system calls (`read`/`write`)  
- **Flat memory layouts** for the map/dp/output buffers, reducing copy overhead  
- **Dynamic programming table stored in a single contiguous memory block** (flat array)  
- **High performance on large maps** (10k×10k processed in ~300 ms, single-threaded)

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

### Run with a file
```bash
./bsq tests/test_10000
```

### Run with stdin
⚠️ This feature has been removed from v2.0.0.
Coming back soon...
```bash
cat tests/basic_test | ./bsq
```

### Clean build files
```bash
# Only clean objects
make clean

# Clean objects and binary
make fclean
```

---

## 🧠 **Key Learnings**

- Understanding **2D dynamic programming** and spatial recurrence  
- Implementing **flat buffered I/O** and avoiding system call overhead  
- Managing **large memory blocks** safely in C  
- Optimizing **C data structures**
- Taking advantage of **C compiler optimizations**
- Writing clean, modular code under the **42 Norm**

---

> _“Think out of the square — then fill it.”_ 🧠
