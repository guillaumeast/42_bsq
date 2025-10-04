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

void	set_boundaries(t_run *run, t_boundary_box *box)
{
	box->x_min = run->solution.last_best.x - run->solution.last_best.value + 1;
	box->x_max = run->solution.last_best.x;
	box->y_min = run->solution.last_best.y - run->solution.last_best.value + 1;
	box->y_max = run->solution.last_best.y;
}

char	is_in_bound(int x, int y, t_boundary_box box)
{
	if (x >= box.x_min && x <= box.x_max && y >= box.y_min && y <= box.y_max)
		return (1);
	return (0);
}

void	set_output(t_run *run)
{
	int				x;
	int				y;
	t_boundary_box	box;

	set_boundaries(run, &box);
	y = 0;
	while (run->map[y] != NULL)
	{
		x = 0;
		while (run->map[y][x] != '\0')
		{
			if (is_in_bound(x, y, box))
				run->solution.output[y][x] = run->rules.filled;
			else
				run->solution.output[y][x] = run->map[y][x];
			x++;
		}
		run->solution.output[y][x] = '\0';
		y++;
	}
}

t_run	*print_result(t_run *run)
{
	int	y;

	if (run->status == ERROR)
		write(1, "map error\n", 10);
	else
	{
		set_output(run);
		y = 0;
		while (run->solution.output[y] != NULL)
		{
			write(1, run->solution.output[y], run->rules.size.width);
			write(1, "\n", 1);
			y++;
		}
	}
	return (run);
}
