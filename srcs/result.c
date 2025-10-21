#include "bsq.h"

static void	compute_bounds(t_bounds *b, size_t rowlen, size_t bsq_i, size_t bsq_size);
static void fill_map(char *map, const size_t row_len, const char fill, const t_bounds *bounds);

void	print_result(t_run *run)
{
	t_bounds	bounds;

	compute_bounds(&bounds, run->row_len, run->bsq_index, run->bsq_size);
	fill_map(run->map, run->row_len, run->rules.fil, &bounds);
	write(1, run->map, run->map_len);
}

static void	compute_bounds(t_bounds *b, size_t rowlen, size_t bsq_i, size_t bsq_size)
{
	b->rowmin = bsq_i / rowlen - (bsq_size - 1);
	b->rowmax = bsq_i / rowlen;
	b->colmin = bsq_i % rowlen - (bsq_size - 1);
	b->colmax = bsq_i % rowlen;
}

static void fill_map(char *map, const size_t row_len, const char fill, const t_bounds *bounds)
{
	size_t		row;
	size_t		col;
	size_t		i;

	row = bounds->rowmin;
	while (row <= bounds->rowmax)
	{
		col = bounds->colmin;
		while (col <= bounds->colmax)
		{
			i = row * row_len + col;
			map[i] = fill;
			col++;
		}
		row++;
	}
}
