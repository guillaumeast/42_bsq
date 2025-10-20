#include "bsq.h"

static t_bool	parse_row(t_run *r, char *map, size_t *i, size_t row);
static void		solve_cell(t_run *run, size_t i, size_t row, size_t col);
static void		set_min(int *dp, size_t i, size_t row_len);

t_rules	*parse_rules(t_str *input, t_rules *r)
{
	int		atoi_res;
	size_t	rules_len;

	if (!input || !r)
		return (NULL);
	rules_len = 0;
	while (rules_len < input->len && input->str[rules_len] != '\n')
		rules_len++;
	if (rules_len < RULES_MIN_LEN)
		return (NULL);
	atoi_res = ft_fast_atoi_n(input, rules_len - RULES_CHARSET_LEN);
	if (atoi_res <= 0)
		return (NULL);
	r->height = atoi_res;
	r->width = 0;
	r->emp = input->str[rules_len - RULES_CHARSET_LEN];
	r->obs = input->str[rules_len - (RULES_CHARSET_LEN - 1)];
	r->fil = input->str[rules_len - (RULES_CHARSET_LEN - 2)];
	if (!is_print(r->emp) || !is_print(r->obs) || !is_print(r->fil))
		return (NULL);
	if (r->emp == r->obs || r->emp == r->fil || r->obs == r->fil)
		return (NULL);
	r->len = rules_len;
	return (r);
}

t_run	*parse_map(t_run *run)
{
	char	*map;
	size_t	map_len;
	size_t	i;
	size_t	row;
	size_t	height;

	if (!run)
		return (NULL);
	map = run->map->str;
	map_len = run->map->len;
	i = 0;
	row = 0;
	height = run->rules.height;
	while (i < map_len)
	{
		if (!parse_row(run, map, &i, row))
			return (run_free(&run));
		if (++row > height)
			return (run_free(&run));
		i++;
	}
	if (row == 0 || row < height)
		return (run_free(&run));
	return (run);
}

static t_bool	parse_row(t_run *run, char *map, size_t *i, size_t row)
{
	t_rules	rules;
	size_t	map_len;
	size_t	col;
	size_t	i_tmp;
	char	c;

	rules = run->rules;
	map_len = run->map->len;
	col = 0;
	i_tmp = *i;
	while (i_tmp < map_len && (c = map[i_tmp]) != '\n')
	{
		if (c != rules.emp && c != rules.obs)
			return (FALSE);
		solve_cell(run, i_tmp++, row, col++);
	}
	if (row == 0)
		run->rules.width = i_tmp - *i;
	else if (rules.width == 0 || i_tmp - *i != rules.width)
		return (FALSE);
	*i = i_tmp;
	return (TRUE);
}

static void	solve_cell(t_run *run, size_t i, size_t row, size_t col)
{
	if (run->map->str[i] == run->rules.obs)
		run->dp[i] = 0;
	else if (row == 0 || col == 0)
		run->dp[i] = 1;
	else
		set_min(run->dp, i, run->rules.width + 1);
	if ((size_t) run->dp[i] > run->bsq.size)
	{
		run->bsq.size = run->dp[i];
		run->bsq.index = i;
	}
}

static void	set_min(int *dp, size_t i, size_t row_len)
{
	int	up;
	int	left;
	int	up_left;

	up = dp[i - row_len];
	left = dp[i - 1];
	up_left = dp[i - row_len - 1];
	if (up_left < up)
		up = up_left;
	if (left < up)
		up = left;
	dp[i] = up + 1;	
}
