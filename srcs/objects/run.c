#include "bsq.h"

t_run	*run_new()
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	run->row_len = 0;
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
	if (map_len == 0)
		return (run_free(run));
	(*run)->map = str_new(map_p, map_len);
	if (!(*run)->map)
		return (run_free(run));
	(*run)->bsq.row = 0;
	(*run)->bsq.col = 0;
	(*run)->bsq.size = 0;
	return ;
}

t_bool dp_init(t_run *run, size_t width)
{
	run->dp = malloc(sizeof *(run->dp));
	if (!run->dp)
		return (FALSE);
	run->dp->prev = malloc((width) * sizeof(int));
	run->dp->curr = malloc((width) * sizeof(int));
	if (!run->dp->prev || !run->dp->curr)
		return (FALSE);
	return (TRUE);
}

void	run_free(t_run **run)
{
	if (!run || !*run)
		return ;
	if ((*run)->input)
	{
		if ((*run)->input->str)
			free((*run)->input->str);
		str_free(&((*run)->input));
	}
	if ((*run)->map)
		free((*run)->map);
	if ((*run)->dp)
	{
		if ((*run)->dp->prev)
			free((*run)->dp->prev);
		if ((*run)->dp->curr)
			free((*run)->dp->curr);
		free((*run)->dp);
	}
	free(*run);
	*run = NULL;
}
