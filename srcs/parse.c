#include "bsq.h"

static t_bool	parse_line(t_run *r, size_t *i);
static void		solve_cell(t_run *run, size_t i);

t_bool	parse(t_run *run, t_str *input)
{
	size_t	map_len;
	size_t	i;

	if (!input || !run_init(run, input))
		return (FALSE);
	map_len = run->map->len;
	i = 0;
	while (i < map_len)
	{
		if (!parse_line(run, &i))
			return (FALSE);
		i++;
	}
	if (run->line_count == 0 || run->line_count < run->rules.height)
		return (FALSE);
	return (TRUE);
}

t_bool	parse_rules(t_str *input, t_rules *r)
{
	size_t	input_len;
	int		atoi_res;
	size_t	rules_len;

	input_len = input->len;
	rules_len = 0;
	while (rules_len < input_len && input->str[rules_len] != '\n')
		rules_len++;
	if (rules_len < RULES_MIN_LEN)
		return (FALSE);
	atoi_res = ft_fast_atoi_n(input, rules_len - RULES_CHARSET_LEN);
	if (atoi_res <= 0)
		return (FALSE);
	r->height = atoi_res;
	r->width = 0;
	r->emp = input->str[rules_len - RULES_CHARSET_LEN];
	r->obs = input->str[rules_len - (RULES_CHARSET_LEN - 1)];
	r->fil = input->str[rules_len - (RULES_CHARSET_LEN - 2)];
	if (!is_print(r->emp) || !is_print(r->obs) || !is_print(r->fil))
		return (FALSE);
	if (r->emp == r->obs || r->emp == r->fil || r->obs == r->fil)
		return (FALSE);
	r->len = rules_len;
	return (TRUE);
}

static t_bool	parse_line(t_run *r, size_t *i)
{
	size_t	j;
	size_t	map_len;

	if (++(r->line_count) > r->rules.height)
		return (FALSE);
	j = *i;
	map_len = r->map->len;
	while (j < map_len && r->map->str[j] != '\n')
	{
		if (r->map->str[j] != r->rules.emp && r->map->str[j] != r->rules.obs)
			return (FALSE);
		solve_cell(r, j);
		j++;
	}
	if (r->line_count == 1)
		r->rules.width = j - *i;
	if (r->rules.width == 0 || j - *i != r->rules.width)
		return (FALSE);
	*i = j;
	return (TRUE);
}

static void	solve_cell(t_run *run, size_t i)
{
	size_t	up;
	size_t	left;
	size_t	up_left;

	if (run->map->str[i] == run->rules.obs)
		run->dp[i] = 0;
	else if (run->line_count == 1 || i % (run->rules.width + 1) == 0)
		run->dp[i] = 1;
	else
	{
		up = run->dp[i - (run->rules.width + 1)];
		left = run->dp[i - 1];
		up_left = run->dp[i - (run->rules.width + 2)];
		if (up < left && up < up_left)
			run->dp[i] = up + 1;
		else if (left < up && left < up_left)
			run->dp[i] = left + 1;
		else
			run->dp[i] = up_left + 1;
	}
	if ((size_t) run->dp[i] > run->bsq.size)
	{
		run->bsq.size = run->dp[i];
		run->bsq.index = i;
	}
}
