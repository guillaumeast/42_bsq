/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 14:49:03 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_run	*init_size(t_run *run_addr)
{
	run_addr->rules.size.width = 0;
	run_addr->rules.size.height = 0;
	return (run_addr);
}
t_run   *clean_size(t_run *run_addr)
{
	return (init_size(run_addr));
}
t_run	*set_size(t_run *run_addr, t_size size)
{
	run_addr->rules.size.width = size.width;
	run_addr->rules.size.height = size.height;
	return (run_addr);
}

t_run	*init_rules(t_run *run_addr)
{
	init_size(run_addr);
	run_addr->rules.empty = '\0';
	run_addr->rules.obstacle = '\0';
	run_addr->rules.filled = '\0';
	return (run_addr);
}
t_run	*clean_rules(t_run *run_addr)
{
	return (init_rules(run_addr));
}
t_run	*set_rules(t_run *run_addr, t_rules rules)
{
    set_size(run_addr, rules.size);
    run_addr->rules.empty = rules.empty;
    run_addr->rules.obstacle = rules.obstacle;
    run_addr->rules.filled = rules.filled;
    return (run_addr);
}

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
t_run	*set_cell(t_run *run_addr, t_cell cell)
{
    run_addr->solution.last_best.x = cell.x;
    run_addr->solution.last_best.y = cell.y;
    run_addr->solution.last_best.value = cell.value;
    return (run_addr);
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
t_run	*set_last_best(t_run *run_addr, t_cell cell)
{
	return (set_cell(run_addr, cell));
}
t_run	*set_solution_table(t_run *run_addr, t_cell cell)
{
	if (run_addr->solution.table != NULL)
		run_addr->solution.table[cell.y][cell.x] = cell.value;
	return (run_addr);
}
t_run   *init_solution_table(t_run *run_addr)
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
t_run	*set_file_content(t_run *run_addr, t_file_content content)
{
	run_addr->content = content;
	return (run_addr);
}

t_run	*init_map(t_run *run_addr)
{
    run_addr->map = NULL;
    return (run_addr);
}
t_run   *clean_map(t_run *run_addr)
{
    if (run_addr->map != NULL)
        ft_free_str_list(&(run_addr->map), -1);
    return (run_addr);
}
t_run	*set_map(t_run *run_addr, t_board_c map)
{
    run_addr->map = map;
    return (run_addr);
}

t_run	init_run(t_file_content content)
{
	t_run	instance;

	init_file_content(&instance);
	init_rules(&instance);
	init_map(&instance);
	init_solution(&instance);
	if (content == NULL)
	{
		instance.status = ERROR;
	}
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

t_run	from_file_to_run(t_filepath path)
{
	return (init_run(ft_read_file(path)));	 
}
t_run	*from_files_to_runs(t_filepath *paths, int size)
{
	return (file_to_run_map(paths, size, from_file_to_run));
}

t_run	from_stdin_to_run(t_filepath path)
{
	return (init_run(ft_read_stdin(path)));	 
}
t_run	*from_stdin_to_runs()
{
	char *_;

	_ = "";
	return (file_to_run_map(&_, 1, from_stdin_to_run));
}

int	main(int argc, char **argv)
{
	t_run	*runs;
	int		size;

	if (argc == 1)
	{
		size = 1;
		runs = from_stdin_to_runs();
	}
	else
	{
		size = argc - 1;
		runs = from_files_to_runs(argv + 1, size);
	}
	run_to_run_map(runs, size, parse);
	run_to_run_map(runs, size, init_solution_table);
	print_debug_run(runs, size);
	printf("After print_debug_run");
}