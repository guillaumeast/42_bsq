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

#include <unistd.h>
#include "bsq.h"

t_run	*print_board(t_run *run);
void	print_debug_content(t_run run);
void	print_debug_rules(t_run run);
void	print_debug_map(t_run run);
void	print_debug_solution(t_run run);
void	print_debug_status(t_run run);
void	print_debug_run(t_run *runs, int size);

void	print_board_1(char **board);

#endif
