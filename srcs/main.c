/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 23:00:01 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"


t_run	from_file_to_run(t_filepath path)
{
	t_run			instance;
	t_file_content	content;
	t_solution		solution;
	t_cell			cell;

	cell.x = 0;
	cell.y = 0;
	cell.value = 0;
	solution.table = NULL;
	solution.last_best = cell;
	instance.rules = NULL;
	instance.map = NULL;
	instance.solution = solution;
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
	
}

int	main(int argc, char **argv)
{
	t_run	*runs;

	if (argc == 1)
		runs = from_stdin_to_runs();
	else
		runs = from_files_to_runs(argv + 1, argc - 1);
	
    solution.table = NULL;
}
