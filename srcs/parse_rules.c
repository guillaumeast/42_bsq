#include "bsq.h"

// Parses and validates the map rules line (height, empty, obstacle, filler)
void	parse_rules(t_run **run, char *input, size_t input_len, t_rules *r)
{
	int		atoi_res;
	size_t	rules_len;

	if (!run || !*run || !input || !r)
		return (run_free(run));
	rules_len = 0;
	while (rules_len < input_len && input[rules_len] != '\n')
		rules_len++;
	if (rules_len == input_len || rules_len < RULES_MIN_LEN)
		return (run_free(run));
	atoi_res = ft_fast_atoi_n(input, rules_len - RULES_CHARSET_LEN);
	if (atoi_res < 1)
		return (run_free(run));
	r->height = (size_t) atoi_res;
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
