/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:49:08 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:05:31 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

#include "bsq.h"

t_boundary_box	*set_boundaries(t_run *run, t_boundary_box *box);
char			is_in_bound(int x, int y, t_boundary_box box);
t_run			*print_board(t_run *run);

#endif
