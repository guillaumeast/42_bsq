/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:32:34 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 11:32:50 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_min_3(t_run *run, int y, int x)
{
    int min;

    min = run->solution.table[y - 1][x - 1];
    if (run->solution.table[y][x - 1] < min)
        min = run->solution.table[y][x - 1];
    if (run->solution.table[y - 1][x] < min)
        min = run->solution.table[y - 1][x];
    return (min);
}

t_run   *set_best(t_run *run, int y, int x)
{
    run->solution.last_best.x = x;
    run->solution.last_best.y = y;
    run->solution.last_best.value = run->solution.table[y][x];
    return (run);
}

t_run   *resolve(t_run *run)
{
    int x;
    int y;

    if (run->status == ERROR)
        return (run);
    y = 0;
    while (run->map[y])
    {
        x = 0;
        while (run->map[y][x])
        {
            if (x == 0 || y ==0)
                run->solution.table[y][x] = 1;
            else if (run->map[y][x] == run->rules.obstacle)
                run->solution.table[y][x] = 0;
            else
                run->solution.table[y][x] = ft_min_3(run, y, x) + 1;
            if (run->solution.table[y][x] > run->solution.last_best.value)
                set_best(run, y, x);
            x++;
        }
        y++;
    }
    return (run);
}
