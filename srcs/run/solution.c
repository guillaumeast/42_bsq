#include "bsq.h"

t_run	*init_cell(t_run *run_addr)
{
	run_addr->solution.last_best.x = 0;
	run_addr->solution.last_best.y = 0;
	run_addr->solution.last_best.value = 0;
	return (run_addr);
}

t_run	*clean_cell(t_run *run_addr)
{
	return (init_cell(run_addr));
}

t_run	*init_solution(t_run *run_addr)
{
	run_addr->solution.table = NULL;
	init_cell(run_addr);
	return (run_addr);
}

t_run	*clean_solution(t_run *run_addr)
{
	if (run_addr->solution.table != NULL)
		ft_free_int_list(&(run_addr->solution.table), -1);
	clean_cell(run_addr);
	return (run_addr);
}

t_run	*init_solution_table(t_run *run_addr)
{
	int	x;
	int	y;
	int width;
	int	height;

	width = run_addr->rules.size.width;
	height = run_addr->rules.size.height;
	if (run_addr->status == ERROR)
		return (run_addr);
	run_addr->solution.table = malloc(sizeof(t_board_i_row) * (height + 1));
	if (run_addr->solution.table == NULL)
		return (clean_run(run_addr));
	y = 0;
	while (y < height)
	{
		run_addr->solution.table[y] = malloc(sizeof(t_board_i_cell) * width);
		if (run_addr->solution.table[y] == NULL)
			return (clean_run(run_addr));
		x = 0;
		while (x < width)
			run_addr->solution.table[y][x++] = 0;
		++y;
	}
	run_addr->solution.table[y] = NULL;
	return (run_addr);
}