/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:46 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:58:02 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include "parse.h"
#include "algo.h"
#include "print.h"
#include "read.h"
#include "utils.h"

typedef enum e_status
{
	VALID,
	ERROR,
}	t_status;

typedef	struct cell
{
	int	x;
	int	y;
	int	value;
}	t_cell;

typedef	struct solution
{
	t_board	table;
	t_cell	last_best;
}	t_solution;

typedef struct run
{
	t_file_content	content;
	t_rules			rules;
	t_board			map;
	t_solution		solution;
	t_status		status;
}	t_run;

#endif
