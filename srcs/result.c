#include "bsq.h"

static void	compute_bounds(t_bounds *b, const t_bsq *bsq);
static void fill_map(t_run *run, t_str *map, const t_rules *rules, const t_bounds *bounds);

void	print_result(t_run *run)
{
	t_bounds	bounds;

	compute_bounds(&bounds, &(run->bsq));
	fill_map(run, run->map, &(run->rules), &bounds);
	write(1, run->map->str, run->map->len);
}

static void	compute_bounds(t_bounds *b, const t_bsq *bsq)
{
	b->rowmin = bsq->row - (bsq->size - 1);
	b->rowmax = bsq->row;
	b->colmin = bsq->col - (bsq->size - 1);
	b->colmax = bsq->col;
}

static void fill_map(t_run *run, t_str *map, const t_rules *rules, const t_bounds *bounds)
{
	size_t		row_len;
	size_t		row;
	size_t		col;
	size_t		i;

	row_len = run->row_len;
	row = bounds->rowmin;
	while (row <= bounds->rowmax)
	{
		col = bounds->colmin;
		while (col <= bounds->colmax)
		{
			i = row * row_len + col;
			map->str[i] = rules->fil;
			col++;
		}
		row++;
	}
}
