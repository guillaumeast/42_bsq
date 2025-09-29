/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 22:14:23 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"


t_run	from_file_to_run(t_filepath path)
{
	t_run			instance;
	t_file_content	content;

	content = ft_read_file(path);
	if (content == NULL)
	{
	    instance.content = NULL;
	    instance.rules = NULL;
	    instance.map = NULL;
	    instance.solution;
	    instance.status;
	}
}

t_run	*from_files_to_runs(t_filepath *paths, int size)
{
	t_run   *

	file_to_run_map(paths, size, );
}

t_run	*generate_run_stdin()
{
	
}

int	main(int argc, char **argv)
{
	t_exercice	*exercices;

	if (argc == 1)
		exercices = generate_exercices_stdin(argv);
	else
		exercices = generate_exercices_files(argv + 1);
	
}
