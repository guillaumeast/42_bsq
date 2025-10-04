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
	int				i;
	t_boundary_box	box;

	set_boundaries(run, &box);
	i = 0;
	y = 0;
	while (y < run->rules.size.height)
	{
		x = 0;
		while (x < run->rules.size.width)
		{
			if (is_in_bound(x, y, box))
				run->solution.output[i] = run->rules.filled;
			else
				run->solution.output[i] = run->map[y][x];
			x++;
			i++;
		}
		run->solution.output[i] = '\n';
		i++;
		y++;
	}
	run->solution.output[i] = '\0';
}

t_run	*print_result(t_run *run)
{
	int	height;
	int	width;

	if (run->status == ERROR)
		write(1, "map error\n", 10);
	else
	{
		height = run->rules.size.height;
		width = run->rules.size.width;
		set_output(run);
		write(1, run->solution.output, height * (width + 1));
	}
	return (run);
}
