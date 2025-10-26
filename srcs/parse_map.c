#include "bsq.h"

static t_bool	parse_row_0(t_run *run, char *map, size_t *i);
static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row);
static void		solve_cell(t_run *run, size_t row, size_t col);
static void		dp_swap(t_dp *dp);

void	parse_map(t_run **run)
{
	char	*map;
	size_t	map_len;
	size_t	i;
	size_t	row;
	size_t	height;

	if (!run || !*run)
		return (run_free(run));
	map = (*run)->map->str;
	map_len = (*run)->map->len;
	height = (*run)->rules.height;
	i = 0;
	if (!parse_row_0(*run, map, &i) || (*run)->width == 0)
		return (run_free(run));
	row = 0;
	while (++i < map_len)
	{
		if (++row == height || !parse_row(*run, map, &i, row))
			return (run_free(run));
		dp_swap((*run)->dp);
	}
	if (map[i - 1] != '\n' || row == 0 || row < height - 1)
		return (run_free(run));
	return ;
}

static t_bool	parse_row_0(t_run *run, char *map, size_t *i)
{
	size_t	col;
	size_t	i_tmp;
	char	c;

	col = 0;
	i_tmp = -1;
	while (++i_tmp < run->map->len && (c = map[i_tmp]) != '\n')
	{
		if (c != run->rules.emp && c != run->rules.obs)
			return (FALSE);
	}
	run->width = i_tmp;
	run->row_len = i_tmp + 1;
	if (!dp_init(run, i_tmp))
		return (FALSE);
	i_tmp = -1;
	while (++i_tmp < run->map->len && (c = map[i_tmp]) != '\n')
	{
		if (c == run->rules.obs)
			run->dp->prev[col++] = 0;
		else
			run->dp->prev[col++] = 1;
	}
	*i = i_tmp;
	return (TRUE);
}

// TODO: solve first cell first (add solve_cell_0() ?)
static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row)
{
	size_t	col;
	size_t	i_tmp;
	char	c;

	col = 0;
	i_tmp = *i - 1;
	while (++i_tmp < run->map->len && (c = map[i_tmp]) != '\n')
	{
		if (c != run->rules.emp && c != run->rules.obs)
			return (FALSE);
		if (c == run->rules.obs)
			run->dp->curr[col++] = 0;
		else if (col == 0)
			run->dp->curr[col++] = 1;
		else
			solve_cell(run, row, col++);
	}
	if (run->width != i_tmp - *i)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

static void	dp_swap(t_dp *dp)
{
	int	*tmp;

	tmp = dp->curr;
	dp->curr = dp->prev;
	dp->prev = tmp;
}

static void	solve_cell(t_run *run, size_t row, size_t col)
{
	int	*curr;
	int	*prev;
	int	min;
	int	dp_value;

	curr = run->dp->curr;
	prev = run->dp->prev;
    min = curr[col - 1];
	if (prev[col - 1] < min)
		min = prev[col - 1];
	if (prev[col] < min)
		min = prev[col];
	dp_value = min + 1;
	curr[col] = dp_value;
	if (dp_value > run->bsq.size)
	{
		run->bsq.size = dp_value;
		run->bsq.row = row;
		run->bsq.col = col;
	}
}
