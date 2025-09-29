/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:20:38 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 18:25:54 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void   ft_free_str(char **str_addr)
{
    free(*str_addr);
    *str_addr = NULL;
}

void	ft_free_board(char ***board_addr, int rows)
{
	int	i;

	i = 0;
	while ((rows != -1 && i < rows) || (rows == -1 && (*board_addr)[i] != NULL))
	{
		free((*board_addr)[i]);
		(*board_addr)[i] = NULL;
		++i;
	}
	free(*board_addr);
	*board_addr = NULL;
}
