#include "bsq.h"

t_run	*run_new()
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	return (run);
}

void	run_add_rules(t_run **run)
{
	char	*map_p;
	size_t	map_len;

	if (!run || !*run)
		return ;
	map_p = (*run)->input->str + (*run)->rules.len + 1;
	map_len = (*run)->input->len - ((*run)->rules.len + 1);
	(*run)->map = str_new(map_p, map_len, (*run)->input->cap);
	(*run)->dp = malloc((*run)->map->len * sizeof(int));
	if (!(*run)->map || !(*run)->dp)
		return (run_free(run));
	(*run)->bsq.index = 0;
	(*run)->bsq.size = 0;
	return ;
}

void	run_free(t_run **run)
{
	if (!run || !*run)
		return ;
	if ((*run)->input)
		str_free(&((*run)->input));
	if ((*run)->dp)
		free((*run)->dp);
	free(*run);
	*run = NULL;
}
