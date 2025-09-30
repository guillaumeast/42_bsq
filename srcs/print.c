/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:52 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:07:23 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "utils.h"
#include "parse.h"
#include "types.h"

void	print_board(t_board_c board)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (board[y] != NULL)
	{
		ft_putstr(board[y]);
		ft_putstr("\n");
		++y;
	}
}

void	print_debug_run(t_run *runs, int size)
{
	int	i;

	i = 0;
	while ()
	{


	}
}
