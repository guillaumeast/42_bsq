/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:42:48 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 10:56:18 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_run	*file_to_run_map(t_filepath *paths, int size, t_run (*act)(t_filepath))
{
	t_run	*runs;
	int		i;

	i = 0;
	runs = malloc(sizeof(t_run) * size);
	while (i < size)
	{
		runs[i] = act(paths[i]);
		++i;
	}
	return (runs);
}

t_run	*run_to_run_map(t_run *instance, int size, t_run *(*act)(t_run *))
{
	int	i;

	i = 0;
	while (i < size)
	{
		act(instance + i);
		++i;
	}
	return (instance);
}