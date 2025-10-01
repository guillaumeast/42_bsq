#include "bsq.h"

t_run	init_run(t_file_content content)
{
	t_run	instance;

	init_file_content(&instance);
	init_rules(&instance);
	init_map(&instance);
	init_solution(&instance);
	if (content == NULL)
		instance.status = ERROR;
	else
	{
		instance.content = content;
		instance.status = VALID;
	}
	return (instance);
}
t_run	*clean_run(t_run *run_addr)
{
	clean_file_content(run_addr);
	clean_rules(run_addr);
	clean_map(run_addr);
	clean_solution(run_addr);
	run_addr->status = ERROR;
	return (run_addr);
}