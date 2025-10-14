# 🧩 **BSQ - 42 Paris Piscine**

> _Fast C CLI that reads maps from files or stdin and prints them back with the largest empty square (dynamic programming + optimized I/O)._

[![Language: C](https://img.shields.io/badge/language-C-lightgrey)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Type: CLI](https://img.shields.io/badge/type-CLI-8b949e)]()
[![Platform: macOS/Linux](https://img.shields.io/badge/platform-macOS%20%26%20Linux-blue)](https://en.wikipedia.org/wiki/Unix-like)
[![Status: Optimized after Piscine](https://img.shields.io/badge/status-Optimized%20after%20Piscine-darkgreen)]()

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
- Compute the **largest empty square** efficiently, even on large maps (e.g. 10k×10k)  
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
- **Buffered I/O** to minimize system calls (`read`/`write`)  
- **Flat memory layout** for the output buffer (`char *`), reducing copy overhead  
- **Dynamic programming table stored entirely in memory** (1 full 2D array)  
- **High performance on large maps** (10k×10k in ~5 s, single-threaded)

---

## 🗂️ **Repository structure**

```
bsq/
├── bsq.subject.en.pdf     # Official 42 subject (English)
├── Makefile               # Build rules and compiler settings (Norm-compliant)
├── includes/              # Header files with type definitions and prototypes
├── srcs/                  # Source files (C code)
│   ├── init/              # Initialization logic (map, rules, runtime setup)
│   ├── utils/             # Utility functions (string, memory, helpers)
│   ├── main.c             # Entry point: handles args and launches BSQ
│   ├── read.c             # Buffered file reading and stdin handling
│   ├── parse.c            # Parses and validates the map structure
│   ├── resolve.c          # Core dynamic programming algorithm
│   └── print.c            # Builds and prints the final map with the largest square
└── tests/                 # Sample maps and performance benchmarks

```

---

## 🧰 **Build and Run**

### Compilation
```bash
make
```

### Run with a file
```bash
./bsq tests/basic_test
```

### Run with stdin
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

## 🧪 **Performance**

| Version | Description | Real Time (10k×10k map) | Peak Memory |
|----------|-------------|------------------------------|--------------|
| **V1 (Piscine)** | Baseline (string join, naïve I/O) | ~37 s | ~820 MB |
| **V2** | Added output buffer (`char **`) | ~5.8 s | ~920 MB |
| **V3** | Switched output to flat buffer (`char *`) | ~5.6 s | ~845 MB |
| **V4** | Removed initialization loops | ~5.4 s | ~845 MB |

---

## 🧠 **Key Learnings**

- Understanding **2D dynamic programming** and spatial recurrence  
- Implementing **buffered I/O** and avoiding system call overhead  
- Managing **large memory blocks** safely in C  
- Writing clean, modular code under the **42 Norm**

---

## 📋 **Compliance**

All code follows the official **42 Norm**:

- ≤ 25 lines per function  
- ≤ 80 columns per line  
- ≤ 5 functions per `.c`  
- ≤ 4 named parameters per function  
- Tabs only, no spaces  
- No ternary, no `for`, no `switch`, no `goto`

---

> _“Think out of the square — then fill it.”_ 🧠
