/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 12:27:37 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

t_rules	init_rules()
{
	t_rules	rules;

	rules.width = 0;
	rules.height = 0;
	rules.empty = '\0';
	rules.obstacle = '\0';
	rules.filled = '\0';
	return (rules);
}

t_run	*clean_rules(t_run *run_addr)
{
	run_addr->rules.width = 0;
	run_addr->rules.height = 0;
	run_addr->rules.empty = '\0';
	run_addr->rules.obstacle = '\0';
	run_addr->rules.filled = '\0';
	return (run_addr);
}

t_cell	init_cell()
{
	t_cell	cell;

	cell.x = 0;
	cell.y = 0;
	cell.value = 0;
	return (cell);
}

t_run	*clean_cell(t_run *run_addr)
{
	run_addr->solution.last_best.x = 0;
	run_addr->solution.last_best.y = 0;
	run_addr->solution.last_best.value = 0;
	return (run_addr);
}

t_solution	init_solution()
{
	t_solution	solution;

	solution.table = NULL;
	solution.last_best = init_cell();
	return (solution);
}

t_run	*clean_solution(t_run *run_addr)
{
	if (run_addr->solution.table != NULL)
		ft_free_str_arr(&(run_addr->solution.table), -1);
    return (run_addr);
}

t_run   *init_solution_table(t_run *run_addr)
{
	int			x;
    int			y;
    t_board_i	table;

	if (run_addr->status == ERROR)
		return (run_addr);
	table = malloc(sizeof(t_board_i_row) * (height + 1));
	if (table == NULL)
		return (on_solution_table_failed(run_addr, NULL));
	y = 0;
	while (y < run->rules.height)
	{
		table[y] = malloc(sizeof(t_board_i_cell) * width);
		if (table[y] == NULL)
			return (on_solution_table_failed(run_addr, &table));
		x = 0;
		while (x < run->rules.width)
			table[y][x++] = 0;
		++y;
    }
	table[y] = NULL;
    run_addr->solution.table = table;
    return (run_addr);
}



t_run	init_run(t_filepath path)
{
	t_run			instance;
	t_file_content	content;

	instance.rules = init_rules();
	instance.map = NULL;
	instance.solution = init_solution();
	content = ft_read_file(path);
	if (content == NULL)
	{
		instance.content = NULL;
		instance.status = ERROR;
	}
	else
	{
		instance.content = content;
		instance.status = VALID;
	}
	return (instance);
}

t_run	*from_files_to_runs(t_filepath *paths, int size)
{
	return (file_to_run_map(paths, size, from_file_to_run);
}

t_run	*from_stdin_to_runs()
{
	t_filepath	_[1];

	_ = '\0';
	return (file_to_run_map(paths, 1, from_file_to_run);
}

t_run	*clean_rules(t_run *run_addr)
{
	run_addr->rules.width = 0;
	run_addr->rules.height = 0;
	run_addr->rules.empty = '\0';
	run_addr->rules.obstacle = '\0';
	run_addr->rules.filled = '\0';
}

t_run	*on_solution_table_failed(t_run *run_addr, t_board *table)
{
	
}

int	main(int argc, char **argv)
{
	t_run	*runs;

	if (argc == 1)
		runs = from_stdin_to_runs();
	else
		runs = from_files_to_runs(argv + 1, argc - 1);
}
