#include "bsq.h"

static void fill_map(t_str *map, const char fil, const t_bounds *b);

void	print_result(t_run *run)
{
	t_bounds	bounds;
	t_bsq		bsq;
	size_t		bsq_row;
	size_t		bsq_col;
	size_t		bsq_size;

	// fprintf(stderr, "\n--------------------\n");
	// fprintf(stderr, "print_result()\n");
	// fprintf(stderr, "--------------------\n");
	bsq = run->bsq;
	bsq_row = bsq.row;
	bsq_col = bsq.col;
	bsq_size = bsq.size;
	// fprintf(stderr, "-> BSQ: size = %zu | row = %zu | col = %zu\n", bsq_size, bsq_row, bsq_col);
	// fprintf(stderr, "-> map.str_len = %zu\n", run->map.str_len);
	bounds.rowmin = bsq_row - (bsq_size - 1);
	bounds.rowmax = bsq_row;
	bounds.colmin = bsq_col - (bsq_size - 1);
	bounds.colmax = bsq_col;
	fill_map(&(run->map), run->rules.fil, &bounds);
	write(1, run->map.p, run->map.str_len);
	// fprintf(stderr, "--------------------\n");
}

static void fill_map(t_str *map, const char fil, const t_bounds *b)
{
	char	*map_start;
	char	*p;
	char	*p_start;
	char	*end;
	size_t	row_len;
	size_t	row_max;
	size_t	col_min;
	size_t	bsq_len;
	size_t	row;

	map_start = map->p;
	row_len = map->row_len;
	row_max = b->rowmax;
	col_min = b->colmin;
	bsq_len = b->colmax - b->colmin + 1;
	row = b->rowmin;
	p_start = map_start + (row * row_len) + col_min;
	while (row <= row_max)
	{
		p = p_start;
		end = p + bsq_len;
		while (p < end)
		{
			*p = fil;
			p++;
		}
		p_start += row_len;
		row++;
	}
}
