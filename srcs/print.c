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
#include <stdio.h>

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

void	print_debug_content(t_run run)
{
	printf("content = %s\n", run.content);
}

void	print_debug_rules(t_run run)
{
	printf("rules\n");
	printf("	size\n");
	printf("		width = %d\n", run.rules.size.width);
	printf("		height = %d\n", run.rules.size.height);
	printf("	empty = %c\n", run.rules.empty);
	printf("	obstacle = %c\n", run.rules.obstacle);
	printf("	filled = %c\n", run.rules.filled);
}

void	print_debug_map(t_run run)
{
	int	x;
	int	y;

	printf("map\n");
	y = 0;
	while (run.map[y] != NULL)
	{
		printf("	%s\n", run.map[y]);
		++y
	}
}

void	print_debug_solution(t_run run)
{
	int	x;
	int y;
	printf("solution\n")
	printf("	table\n");
	y = 0;
	while (y < run.rules.size.height)
	{
		printf("		");
		while (x < run.rules.size.width)
		{
			printf("%d", run.solution.table[y][x]);
			++x;
		}
		printf("\n");
		++y;
	}
	printf("	last_best\n");
	printf("		x = %d\n", run.solution.last_best.x);
	printf("		y = %d\n", run.solution.last_best.y);
	printf("		value = %d\n", run.solution.last_best.value);
}

void	print_debug_status(t_run run)
{
	if (run.status == ERROR)
		printf("status = ERROR\n");
	else
		printf("status = VALID\n");
}

void	print_debug_run(t_run *runs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("DEBUG RUN %d\n", i);
		print_debug_content(run[i]);
		printf("\n--------\n");
		print_debug_rules(run[i]);
		printf("\n--------\n");
		print_debug_map(run[i]);
		printf("\n--------\n");
		print_debug_solution(run[i]);
		printf("\n--------\n");
		print_debug_status(run[i]);
		printf("\n================================\n");
	}
}
