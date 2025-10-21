#include "bsq.h"

t_run	*run_new()
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	return (run);
}

void	run_add_rules(t_run **run_p)
{
	t_run	*run;
	size_t	offset;
	size_t	map_len;

	if (!run_p || !*run_p)
		return ;
	run = *run_p;
	offset = run->rules.len + 1;
	map_len = run->input_len - offset;
	run->row_len = run->rules.width + 1;
	run->map = run->input + offset;
	run->map_len = map_len;
	run->dp = malloc(map_len * sizeof(int));
	if (!run->dp)
		return (run_free(run_p));
	run->bsq_index = 0;
	run->bsq_size = 0;
	return ;
}

void	run_free(t_run **run)
{
	if (!run || !*run)
		return ;
	if ((*run)->input)
		free((*run)->input);
	if ((*run)->dp)
		free((*run)->dp);
	free(*run);
	*run = NULL;
}
