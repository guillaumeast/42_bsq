#include "bsq.h"

static t_bool	parse_row(t_run *r, char *map, size_t *i, size_t row);
static void		solve_cell(t_run *run, size_t i, size_t row, size_t col);

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

	if (!run || !*run)
		return ;
	map = (*run)->map->str;
	map_len = (*run)->map->len;
	height = (*run)->rules.height;
	i = 0;
	row = 0;
	while (i < map_len)
	{
		if (!parse_row(*run, map, &i, row))
			return (run_free(run));
		if (++row > height)
			return (run_free(run));
		i++;
	}
	if (row == 0 || row < height)
		return (run_free(run));
	return ;
}

static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row)
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
	while (i_tmp < run->map->len && (c = map[i_tmp]) != '\n')
	{
		if (c != emp && c != obs)
			return (FALSE);
		solve_cell(run, i_tmp++, row, col++);
	}
	if (row == 0)
	{
		if (!run_set_width(run, i_tmp - *i))
			return (FALSE);
	}
	else if (run->width != i_tmp - *i)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

static void	solve_cell(t_run *run, size_t i, size_t row, size_t col)
{
	int		up;
	int		left;
	int		up_left;

	if (run->map->str[i] == run->rules.obs)
		run->dp[i] = 0;
	else if (row == 0 || col == 0)
		run->dp[i] = 1;
	else
	{
		up = run->dp[i - run->row_len];
		left = run->dp[i - 1];
		up_left = run->dp[i - run->row_len - 1];
		if (up_left < up)
			up = up_left;
		if (left < up)
			up = left;
		run->dp[i] = up + 1;
	}
	if (run->dp[i] > run->bsq.size)
	{
		run->bsq.size = run->dp[i];
		run->bsq.index = i;
	}
}
