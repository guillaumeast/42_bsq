## [2.0.0]
### Added
- Unified parsing and solving logic (single-pass DP computation)
- New `t_str` structure for efficient dynamic strings
- Optimized flat memory layout for map and DP arrays
- Added detailed performance metrics and timing display (in ms)
- Added ASCII box output for runtime statistics

### Changed
- Fully rewritten buffered I/O system using `read()` and dynamic growth
- Removed all `ft_split()`, `ft_strlen()`, `ft_strncat()`, `ft_strndup()` calls
- Simplified data structures of `t_run`

### Performance
- Processing time for a 10k×10k map: **~300 ms** (vs. ~5 400 ms in last version)
- Memory usage reduced by ~30% thanks to flattened arrays
- Verified single-threaded consistency on macOS and Linux

---

## [1.4.0]
### Added
- Removed table/output initialisations
- Used height/width instead of checking map

---

## [1.3.0]
### Added
- Converted output from `char **` to `char *`

---

## [1.2.0]
### Added
- Added output buffer `char **`

---

## [1.1.0]
- Initial version developed during the 42 Paris Piscine
- Implemented naive I/O and line-by-line parsing - O(n²)

---

> _“Think out of the square — then fill it.”_ 🧠
