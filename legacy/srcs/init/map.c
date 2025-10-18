/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:03:59 by gastesan          #+#    #+#             */
/*   Updated: 2025/10/01 13:04:01 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_run	*init_map(t_run *run_addr)
{
	run_addr->map = NULL;
	return (run_addr);
}

t_run	*clean_map(t_run *run_addr)
{
	if (run_addr->map != NULL)
		ft_free_str_list(&(run_addr->map), -1);
	return (run_addr);
}
