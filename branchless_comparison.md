# Understanding _bitmasks- and XOR-based branchless comparison_ (without an `if` statement)

> _All examples use 4-bit numbers for easier visualization_

---

## _Two’s complement_ (binary representation of negative numbers)

Negative numbers are represented by inverting all bits of the positive number and then adding 1:
```c
a 		= 0001		// 1
~a 		= 1110		// Opposite of a (invert all bits)
~a + 1	= 1111		// Add 1
```

+0 and −0 merge into a single representation due to overflow:
```c
a 		=   0000	// 0
~a 		=   1111	// Opposite of a (invert all bits)
~a + 1	= 1 0000	// Add 1 → Overflow → We only keep 8 bits → 0000
```

This method allows standard arithmetic to work for both positive and negative binary numbers:
```c
	1111			//   (-1)
+   0001			// + (+1)
-------------
= 1 0000			// Overflow → We only keep 8 bits → 0000 = 0
```

---

## _AND_ + _OR_ comparison

### Detailed process for `a < b`

``` c
a =							0101	// Binary value for 5
b =							1100	// Binary value for 12

comp = a < b =				0001 	// TRUE = `1`, FALSE = `0`

mask = -comp =				1111	// -1 = 1111
~mask =						0000	// Opposite of mask (invert all bits)

a_masked = a & mask =		0101	// Keeps all bits from a because mask = 1111
b_masked = b & ~mask =		0000	// Keeps no bits from b because ~mask = 0000

min = a_masked | b_masked =	0101	// Keeps all 1 from a_masked and b_masked => min = 5 = a
```

### Detailed process for `b < a`

``` c
a =							1100	// Binary value for 12
b =							0101	// Binary value for 5

comp = a < b =				0000 	// TRUE = `1`, FALSE = `0`

mask = -comp =				0000	// -0 = 0 = 0000
~mask =						1111	// Opposite of mask

a_masked = a & mask = 		0000	// Keeps no bits from a because mask = 0000
b_masked = b & ~mask =		0101	// Keeps all bits from b because ~mask = 1111

min = a_masked | b_masked =	0101	// Keeps all 1 from a_masked and b_masked => min = 5 = b
```

### Usage

```c
mask = -(a < b);					// Generate mask
min = (a & mask) | (b & ~mask)		// Use mask
```

---

## _XOR_ comparison

> _XOR_ gates keep 1 when _only 1_ of the two bits is equal to 1

### Detailed process for `a < b`

```c
a =					0101	// 5
b =					1100	// 12
xor = a ^ b =		1001	// XOR

comp = a < b =		0001	// TRUE = `1`, FALSE = `0`
mask = -comp =		1111	// -1 = 1111

res = xor & mask =	1001	// Keeps all bits from xor because mask = 1111

min = b ^ res =		0101	// 5
```

### Detailed process for `b < a`

```c
a =					1100	// 12
b =					0101	// 5
xor = a ^ b =		1001	// XOR

comp = a < b =		0000	// TRUE = `1`, FALSE = `0`
mask = -comp =		0000	// -0 = 0 = 0000

res = xor & mask =	0000	// Keeps no bits from xor because mask = 0000
b =					0101	// 5

min = b ^ res =		0101	// 5
```

### Usage

#### Step by step:

```c
xor = a ^ b;		// 1001 (for a = 5 = 0101 and b = 12 = 1100)
mask = -(a < b);	// 1111
res = xor & mask;	// 1001
min = b ^ res;		// 0101 (5)
```

#### Partially inlined:

```c
res = (a ^ b) & -(a < b);	// 1001 (for a = 5 = 0101 and b = 12 = 1100)
min = b ^ res;				// 0101 (5)
```

#### Fully inlined:

```c
min = b ^ ((a ^ b) & -(a < b));
```

Or:
```c
mask = 1111;
b ^ ((a ^ b) & mask) = b ^ (a ^ b) = a;
```

Or:
```c
mask = 1111;
b ^ ((a ^ b) & mask) = b ^ 0000 = b;
```

Or more visually, imagine a function `xor(x, y) = {x ^ y}`:
```c
min = xor(b, (xor(a, b) & mask));
```

## Test it in Compiler Explorer

Go to [Compiler Explorer website](https://godbolt.org/) and see by yourself that the `clang` compiler automatically full optimizes the min computing into a single `csel` call since `-O1` optimization flag, even for the _if-based_ version:

1. Compiler
```
armv8-a clang 17.0.1
```

2. Flags
```bash
-O0		# No optimization (42-like)
# OR
-O1		# First level optimization (csel used)
```

3. Code
```c
#include <stdint.h>		// Import uint32_t type

int	min_if(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

uint32_t min_mask(uint32_t a, uint32_t b)
{
    uint32_t mask = -(a < b);
    return ((a & mask) | (b & ~mask));
}

uint32_t min_xor(uint32_t a, uint32_t b)
{
    return (b ^ ((a ^ b) & -(a < b)));
}
```
