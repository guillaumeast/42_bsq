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

#include "bsq.h"

t_boundary_box	*set_boundaries(t_run *run, t_boundary_box *box)
{
	box->x_min = run->solution.last_best.x - run->solution.last_best.value + 1;
	box->x_max = run->solution.last_best.x;
	box->y_min = run->solution.last_best.y - run->solution.last_best.value + 1;
	box->y_max = run->solution.last_best.y;
	return (box);
}

char	is_in_bound(int x, int y, t_boundary_box box)
{
	if (x >= box.x_min && x <= box.x_max && y >= box.y_min && y <= box.y_max)
		return (1);
	return (0);
}

t_run	*print_result(t_run *run)
{
	if (run->status == ERROR)
		write(1, "map error\n", 10);
	else
		print_board(run);
	return (run);
}

t_run	*print_board(t_run *run)
{
	int				x;
	int				y;
	t_boundary_box	box;

	if (run->status == ERROR)
		return (run);
	set_boundaries(run, &box);
	y = 0;
	while (run->map[y] != NULL)
	{
		x = 0;
		while (run->map[y][x] != '\0')
		{
			if (is_in_bound(x, y, box))
				write(1, &(run->rules.filled), 1);
			else
				write(1, &(run->map[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
	return (run);
}
/*
void	print_debug_content(t_run run)
{
	printf("content = \n%s\n", run.content);
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
	int	y;

	printf("map\n");
	if (run.map == NULL)
		printf("%p\n", run.map);
	else
	{
		y = 0;
		while (run.map[y] != NULL)
		{
			printf("	%s\n", run.map[y]);
			++y;
		}
	}
}
void	print_board_1(char **board)
{
	int y;

	y = 0;
	while (board[y] != NULL)
	{
		printf("	%s\n", board[y]);
		++y;
	}
}
void	print_debug_solution(t_run run)
{
	int	x;
	int y;
	printf("solution\n");
	printf("	table\n");
	y = 0;
	while (y < run.rules.size.height)
	{
		x = 0;
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
		if (runs[i].status != ERROR)
		{
			print_debug_content(runs[i]);
			printf("\n--------\n");
			print_debug_rules(runs[i]);
			printf("\n--------\n");
			print_debug_map(runs[i]);
			printf("\n--------\n");
			print_debug_solution(runs[i]);
			printf("\n--------\n");
			print_debug_status(runs[i]);
			printf("\n================================\n");
		}
		else
			printf("ERROR\n");
		++i;
	}
}*/