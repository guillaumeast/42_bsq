#include "bsq.h"

static void	compute_bounds(t_bounds *b, const size_t rowlen, const t_bsq *bsq);
static void fill_map(t_run *run, t_str *map, const t_rules *rules, const t_bounds *bounds);

void	print_result(t_run *run)
{
	t_bounds	bounds;

	compute_bounds(&bounds, run->row_len, &(run->bsq));
	fill_map(run, run->map, &(run->rules), &bounds);
	write(1, run->map->str, run->map->len);
}

static void	compute_bounds(t_bounds *b, const size_t rowlen, const t_bsq *bsq)
{
	b->rowmin = bsq->index / rowlen - ((size_t) bsq->size - 1);
	b->rowmax = bsq->index / rowlen;
	b->colmin = bsq->index % rowlen - ((size_t) bsq->size - 1);
	b->colmax = bsq->index % rowlen;
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
