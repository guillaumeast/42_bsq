## [2.4.1] - ~100 ms on 10,000 x 10,000 maps
- Avoid useless last buffer grow
- Refactored main.c, run.c, parse.c and bench.c
- Fix multiple freeing of not allocated pointers
- Fix multiple files handling

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

## [1.4.0] - ~5 400 ms on 10 000 x 10 000 maps
- Removed table/output initialisations
- Used height/width instead of checking map

---

## [1.3.0] - ~5 600 ms on 10 000 x 10 000 maps
- Converted output from `char **` to `char *`

---

## [1.2.0] - ~5 800 ms on 10 000 x 10 000 maps
- Added output buffer `char **`

---

## [1.1.0] - ~37 000 ms on 10 000 x 10 000 maps
- Initial version developed during the 42 Paris Piscine
- Implemented naive I/O and line-by-line parsing - O(n²)

---

> _“Think out of the square — then fill it.”_ 🧠
