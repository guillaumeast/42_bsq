#include "bsq.h"

static t_bool	parse_row_0(t_run *run, char *map, size_t *i);
static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row);
static t_bool	parse_col_0(char map_cell, t_dp *dp, char empty, char obs);
static void		solve_cell(t_run *run, size_t row, size_t col);

void	parse_map(t_run **run)
{
	char	*map;
	size_t	map_len;
	size_t	i;
	size_t	row;

	// fprintf(stderr, "\n--------------------\n");
	// fprintf(stderr, "parse_map()\n");
	// fprintf(stderr, "--------------------\n");
	if (!run || !*run)
	{
		// fprintf(stderr, "INVALID RUN ARG\n");
		return (run_free(run));
	}
	map = (*run)->map.p;
	map_len = (*run)->map.str_len;
	i = 0;
	// fprintf(stderr, "Parsing row 0...\n");
	if (!parse_row_0(*run, map, &i) || (*run)->map.row_width == 0)
		return (run_free(run));
	row = 1;
	while (++i < map_len)
	{
		if (!parse_row(*run, map, &i, row++))
			return (run_free(run));
	}
	// fprintf(stderr, "=> All rows parsed\n");
	if (map[i - 1] != '\n')
		return (run_free(run));
	// fprintf(stderr, "--------------------\n");
	return ;
}

static t_bool	parse_row_0(t_run *run, char *map, size_t *i)
{
	size_t	col;
	size_t	i_tmp;
	size_t	width;
	char	c;
	int		*dp_tab;
	char	obs;
	char	emp;

	i_tmp = 0;
	col = 0;
	width = run->map.row_width;
	dp_tab = run->dp.tab;
	emp = run->rules.emp;
	obs = run->rules.obs;
	// fprintf(stderr, "width = %zu\n", width);
	while (i_tmp < width)
	{
		c = map[i_tmp];
		if (c == obs)
			dp_tab[col++] = 0;
		else if (c == emp)
			dp_tab[col++] = 1;
		else
		{
			// fprintf(stderr, "---> Invalid char '%c' at col %zu\n", c, col);
			return (FALSE);
		}
		i_tmp++;
	}
	*i = i_tmp;
	return (TRUE);
}

static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row)
{
	size_t	col;
	size_t	i_tmp;
	char	c;
	size_t	len;
	int		*dp_prev;
	int		*dp_tab;
	char	obs;
	char	emp;

	obs = run->rules.obs;
	emp = run->rules.emp;
	if (!parse_col_0(map[*i], &(run->dp), emp, obs))
		return (FALSE);
	col = 1;
	i_tmp = *i;
	len = run->map.str_len;
	dp_prev = &(run->dp.prev);
	dp_tab = run->dp.tab;
	while (++i_tmp < len && (c = map[i_tmp]) != '\n')
	{
		if (c == obs)
		{
			*dp_prev = dp_tab[col];
			dp_tab[col++] = 0;
		}
		else if (c == emp)
			solve_cell(run, row, col++);
		else
			return (FALSE);
	}
	if (run->map.row_width != i_tmp - *i)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

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

	prev = run->dp.prev;
	tab = run->dp.tab;
    min = tab[col - 1];
	if (prev < min)
		min = prev;
	if (tab[col] < min)
		min = tab[col];
	dp_value = min + 1;
	run->dp.prev = tab[col];
	tab[col] = dp_value;
	if (dp_value > run->bsq.size)
	{
		run->bsq.size = dp_value;
		run->bsq.row = row;
		run->bsq.col = col;
	}
}
