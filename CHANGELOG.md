## [2.1.1] - ~250 ms on 10 000 x 10 000 maps
- Added **integrated benchmark mode**
- Added **average** timings to the displayed performance metrics

### Important benchmark modifications
- The benchmark is now run with `stdout` redirected to `/dev/null` instead of a file to eliminate potential shell or terminal I/O bottlenecks  
- This change alone results in a **~50 ms improvement**

## [2.1.0] - ~250 ms on 10 000 x 10 000 maps
### Changed
- **Modifies the initial map** (`char *`) instead of creating a new one for output
- Avoids full map copies — **only updates required characters**

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
