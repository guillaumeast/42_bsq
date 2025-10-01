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
