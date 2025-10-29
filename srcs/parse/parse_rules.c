#include "bsq.h"

static int		ft_fast_atoi_n(char *str, size_t n);
static t_bool	is_print(char c1, char c2, char c3);

void	parse_rules(t_run **run)
{
	t_rules	*r;
	char	*input;
	size_t	width;
	int		atoi_res;

	// fprintf(stderr, "\n--------------------\n");
	// fprintf(stderr, "parse_rules()\n");
	// fprintf(stderr, "--------------------\n");
	if (!run || !*run)
		return ;
	r = &((*run)->rules);
	input = r->input.p;
	width = r->input.row_width;
	// fprintf(stderr, "width = %zu | MIN = %d | MAX = %d\n", width, RULES_MIN_WIDTH, RULES_MAX_WIDTH);
	if (width < RULES_MIN_WIDTH || width > RULES_MAX_WIDTH)
		return (run_free(run));
	atoi_res = ft_fast_atoi_n(input, width - RULES_CHARSET_LEN);
	if (atoi_res < 1)
		return (run_free(run));
	r->height = (size_t) atoi_res;
	r->emp = input[width - RULES_CHARSET_LEN];
	r->obs = input[width - (RULES_CHARSET_LEN - 1)];
	r->fil = input[width - (RULES_CHARSET_LEN - 2)];
	// fprintf(stderr, "=> height = %zu | emp = %c | obs = %c | fil = %c\n", r->height, r->emp, r->obs, r->fil);
	if (!is_print(r->emp, r->obs, r->fil))
		return (run_free(run));
	if (r->emp == r->obs || r->emp == r->fil || r->obs == r->fil)
		return (run_free(run));
	// fprintf(stderr, "--------------------\n");
	return ;
}

static int	ft_fast_atoi_n(char *str, size_t n)
{
	char	*end;
	int		result = 0;

	end = str + n;
	while (str < end)
	{
		if ((unsigned char) (*str - '0') < 10)
			result = result * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return (result);
}

static t_bool	is_print(char c1, char c2, char c3)
{
	return (c1 > 31 && c1 < 127 && c2 > 31 && c2 < 127 && c3 > 31 && c3 < 127);
}
