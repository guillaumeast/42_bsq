#include "bsq.h"

static t_bool	parse_r1(t_run *run, char *map, size_t *i, size_t row);
static t_bool	parse_r2(t_run *run, char *map, size_t *i, size_t row);
static void		solve_dp1(t_run *run, size_t row, size_t col);
static void		solve_dp2(t_run *run, size_t row, size_t col);

void	parse_rules(t_run **run, char *input, size_t input_len, t_rules *r)
{
	size_t	atoi_res;
	size_t	rules_len;

	if (!run || !*run || !input || !r)
		return ;
	rules_len = 0;
	while (rules_len < input_len && input[rules_len] != '\n')
		rules_len++;
	if (rules_len < RULES_MIN_LEN)
		return (run_free(run));
	atoi_res = ft_fast_atoi_n(input, rules_len - RULES_CHARSET_LEN);
	if (atoi_res <= 0)
		return (run_free(run));
	r->height = atoi_res;
	r->emp = input[rules_len - RULES_CHARSET_LEN];
	r->obs = input[rules_len - (RULES_CHARSET_LEN - 1)];
	r->fil = input[rules_len - (RULES_CHARSET_LEN - 2)];
	if (!is_print(r->emp) || !is_print(r->obs) || !is_print(r->fil))
		return (run_free(run));
	if (r->emp == r->obs || r->emp == r->fil || r->obs == r->fil)
		return (run_free(run));
	r->len = rules_len;
	run_add_rules(run);
	return ;
}

void	parse_map(t_run **run)
{
	char	*map;
	size_t	map_len;
	size_t	i;
	size_t	row;
	size_t	height;

	if (!run || !*run || !run_set_width(*run))
		return (run_free(run));
	map = (*run)->map->str;
	map_len = (*run)->map->len;
	height = (*run)->rules.height;
	i = 0;
	row = 0;
	while (i < map_len)
	{
		if (row > height || !parse_r1(*run, map, &i, row++))
			return (run_free(run));
		i++;
		if (row < height && !parse_r2(*run, map, &i, row++))
			return (run_free(run));
		i++;
	}
	if (row == 0 || row < height)
		return (run_free(run));
	return ;
}

static t_bool	parse_r1(t_run *run, char *map, size_t *i, size_t row)
{
	char	emp;
	char	obs;
	size_t	col;
	size_t	i_tmp;
	char	c;

	emp = run->rules.emp;
	obs = run->rules.obs;
	col = 0;
	i_tmp = *i - 1;
	while (++i_tmp < run->map->len && (c = map[i_tmp]) != '\n') // TODO: && i_tmp < run->row_len
	{
		if (c != emp && c != obs)
			return (FALSE);
		if (c == obs)
			run->dp->dp1[col] = 0;
		else if (row == 0 || col == 0)
			run->dp->dp1[col] = 1;
		else
			solve_dp1(run, row, col++);
	}
	if (run->width != i_tmp - *i)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

static t_bool	parse_r2(t_run *run, char *map, size_t *i, size_t row)
{
	char	emp;
	char	obs;
	size_t	col;
	size_t	i_tmp;
	char	c;

	emp = run->rules.emp;
	obs = run->rules.obs;
	col = 0;
	i_tmp = *i;
	while (++i_tmp < run->map->len && (c = map[i_tmp]) != '\n') // TODO: && i_tmp < run->row_len
	{
		if (c != emp && c != obs)
			return (FALSE);
		if (c == obs)
			run->dp->dp2[col] = 0;
		else if (row == 0 || col == 0)
			run->dp->dp2[col] = 1;
		else
			solve_dp2(run, row, col++);
	}
	if (run->width != i_tmp - *i)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

static void	solve_dp1(t_run *run, size_t row, size_t col)
{
	int	*dp1;
	int	*dp2;
	int	min;

	dp1 = run->dp->dp1;
	dp2 = run->dp->dp2;
	min = dp2[col];
	if (dp1[col - 1] < min)
		min = dp1[col - 1];
	if (dp2[col - 1] < min)
		min = dp2[col - 1];
	dp1[col] = min + 1;
	if (dp1[col] > run->bsq.size)
	{
		run->bsq.size = dp1[col];
		run->bsq.row = row;
		run->bsq.col = col;
	}
}

static void	solve_dp2(t_run *run, size_t row, size_t col)
{
	int	*dp1;
	int	*dp2;
	int	min;

	dp1 = run->dp->dp1;
	dp2 = run->dp->dp2;
	min = dp1[col];
	if (dp2[col - 1] < min)
		min = dp2[col - 1];
	if (dp1[col - 1] < min)
		min = dp1[col - 1];
	dp2[col] = min + 1;
	if (dp2[col] > run->bsq.size)
	{
		run->bsq.size = dp2[col];
		run->bsq.row = row;
		run->bsq.col = col;
	}
}
