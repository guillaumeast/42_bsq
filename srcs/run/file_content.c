/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:03:53 by gastesan          #+#    #+#             */
/*   Updated: 2025/10/01 13:03:54 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
