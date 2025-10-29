#include "bsq.h"

t_run	*run_new()
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	init_buffer(&(run->buffer));
	init_rules(&(run->rules));
	init_str(&(run->map));
	init_dp(&(run->dp));
	init_bsq(&(run->bsq));
	return (run);
}

void	run_free(t_run **run)
{
	if (!run || !*run)
		return ;
	if ((*run)->buffer.data)
		free((*run)->buffer.data);
	if ((*run)->dp.tab)
		free((*run)->dp.tab);
	free(*run);
	*run = NULL;
}
