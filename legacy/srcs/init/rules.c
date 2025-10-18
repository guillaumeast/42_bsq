/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:04:06 by gastesan          #+#    #+#             */
/*   Updated: 2025/10/01 13:04:09 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_run	*init_size(t_run *run_addr)
{
	run_addr->rules.size.width = 0;
	run_addr->rules.size.height = 0;
	return (run_addr);
}

t_run	*clean_size(t_run *run_addr)
{
	return (init_size(run_addr));
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
