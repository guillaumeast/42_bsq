#include "bsq.h"

t_run	*init_file_content(t_run *run_addr)
{
	run_addr->content = NULL;
	return (run_addr);
}
t_run	*clean_file_content(t_run *run_addr)
{
	if (run_addr->content != NULL)
		ft_free_str(&(run_addr->content));
	return (run_addr);
}