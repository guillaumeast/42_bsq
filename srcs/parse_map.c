#include "bsq.h"

static t_bool	parse_row_0(t_run *run, char *map, size_t *i);
static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row);
static t_bool	parse_col_0(char map_cell, t_dp *dp, char empty, char obs);
static void		solve_cell(t_run *run, size_t row, size_t col);

// Parses the map and solves the DP for all rows
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
	}
	if (map[i - 1] != '\n' || row == 0 || row < height - 1)
		return (run_free(run));
	return ;
}

// Parses and solves the first row (initial DP setup)
static t_bool	parse_row_0(t_run *run, char *map, size_t *i)
{
	size_t	col;
	size_t	i_tmp;
	char	c;

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
	col = 0;
	while (++i_tmp < run->width)
	{
		if (map[i_tmp] == run->rules.obs)
			run->dp->tab[col++] = 0;
		else
			run->dp->tab[col++] = 1;
	}
	*i = i_tmp;
	return (TRUE);
}

// Parses and solves all rows except the first one
static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row)
{
	size_t	col;
	size_t	i_tmp;
	char	c;

	if (!parse_col_0(map[*i], run->dp, run->rules.emp, run->rules.obs))
		return (FALSE);
	col = 1;
	i_tmp = *i;
	while (++i_tmp < run->map->len && (c = map[i_tmp]) != '\n')
	{
		if (c == run->rules.obs)
		{
			run->dp->prev = run->dp->tab[col];
			run->dp->tab[col++] = 0;
		}
		else if (c == run->rules.emp)
			solve_cell(run, row, col++);
		else
			return (FALSE);
	}
	if (run->width != i_tmp - *i)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

// Parses and solves the first column of each row (except the first row)
static t_bool	parse_col_0(char map_cell, t_dp *dp, char empty, char obs)
{
	dp->prev = dp->tab[0];
	if (map_cell == obs)
	{
		dp->tab[0] = 0;
		return (TRUE);
	}
	if (map_cell == empty)
	{
		dp->tab[0] = 1;
		return (TRUE);
	}
	return (FALSE);
}

/* Computes `dp->tab[col]` and updates `bsq` if needed

(Uses a single-row array DP for faster updates)
1. Up-left	= `dp->prev`
2. Up		= `dp->tab[col]`
3. Left		= `dp->tab[col - 1]`
4. `dp->prev` is set to `dp->tab[col]` before modification
5. `bsq` is updated if `dp->tab[col] > bsq->size`
*/
static void	solve_cell(t_run *run, size_t row, size_t col)
{
	int	prev;
	int	*tab;
	int	min;
	int	dp_value;

	prev = run->dp->prev;
	tab = run->dp->tab;
    min = tab[col - 1];
	if (prev < min)
		min = prev;
	if (tab[col] < min)
		min = tab[col];
	dp_value = min + 1;
	run->dp->prev = tab[col];
	tab[col] = dp_value;
	if (dp_value > run->bsq.size)
	{
		run->bsq.size = dp_value;
		run->bsq.row = row;
		run->bsq.col = col;
	}
}
