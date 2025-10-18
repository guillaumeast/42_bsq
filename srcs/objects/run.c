#include "bsq.h"

t_bool	run_init(t_run *run, t_str *input)
{
	run->input = input;
	if (!parse_rules(input, &(run->rules)))
		return (FALSE);
	run->map = str_new(0);
	run->map->str = input->str + run->rules.len + 1;
	run->map->cap = input->cap;
	run->map->len = input->len - (run->rules.len + 1);
	run->line_count = 0;
	run->dp = malloc(run->map->len * sizeof(int));
	if (!run->dp)
	{	
		run->dp = NULL;
		return (FALSE);
	}
	run->bsq.size = 0;
	run->bsq.index = 0;
	return (TRUE);
}

t_run	*run_free(t_run *run)
{
	if (!run)
		return (NULL);
	if (run->input)
		str_free(&(run->input));
	if (run->dp)
		free(run->dp);
	return (NULL);
}
