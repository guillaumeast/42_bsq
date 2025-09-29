/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 00:11:09 by adouieb          ###   ########.fr       */
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

t_cell	init_cell()
{
	t_cell	cell;

	cell.x = 0;
	cell.y = 0;
	cell.value = 0;
	return (cell);
}

t_solution	init_solution()
{
	t_solution	solution;

	solution.table = NULL;
	solution.last_best = init_cell();
	return (solution);
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

void	on_solution_table_failed(t_run run)
{
	
}

t_run	init_solution_table(t_run run)
{
	if (run.status == ERROR)
		return (run);
	
}

int	main(int argc, char **argv)
{
	t_run	*runs;

	if (argc == 1)
		runs = from_stdin_to_runs();
	else
		runs = from_files_to_runs(argv + 1, argc - 1);
}
