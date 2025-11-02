#include "bsq.h"

static void fill_map(size_t len, char *map, const char fil, const t_bounds *b);

// Prints the final `map` with the largest square filled
void	print_result(t_run *run)
{
	t_bounds	bounds;
	t_bsq		bsq;
	size_t		bsq_row;
	size_t		bsq_col;
	size_t		bsq_size;

	bsq = run->bsq;
	bsq_row = bsq.row;
	bsq_col = bsq.col;
	bsq_size = bsq.size;
	bounds.rowmin = bsq_row - (bsq_size - 1);
	bounds.rowmax = bsq_row;
	bounds.colmin = bsq_col - (bsq_size - 1);
	bounds.colmax = bsq_col;
	fill_map(run->row_len, run->map->str, run->rules.fil, &bounds);
	write(1, run->map->str, run->map->len);
}

// Fills the `map` with the filler character within the given square bounds
static void fill_map(size_t len, char *map, const char fil, const t_bounds *b)
{
	size_t		row;
	size_t		col;
	size_t		i;

	row = b->rowmin;
	while (row <= b->rowmax)
	{
		col = b->colmin;
		while (col <= b->colmax)
		{
			i = row * len + col;
			map[i] = fil;
			col++;
		}
		row++;
	}
}
