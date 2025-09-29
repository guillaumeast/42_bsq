/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:20:38 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 22:17:15 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_rules(t_rules **rules)
{
	free(*rules);
	*rules = NULL;
}

void	ft_free_str(char **str_addr)
{
    free(*str_addr);
    *str_addr = NULL;
}

void	ft_free_str_list(char ***str_arr_addr, int n)
{
	int	i;

	i = 0;
	while ((n != -1 && i < n) || (n == -1 && (*str_arr_addr)[i] != NULL))
	{
		free((*str_arr__addr)[i]);
		(*str_arr_addr)[i] = NULL;
		++i;
	}
	free(*str_arr_addr);
	*str_arr_addr = NULL;
}
