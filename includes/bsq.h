/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:46 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 14:41:59 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "types.h"
#include "parse.h"
#include "algo.h"
#include "print.h"
#include "read.h"
#include "utils.h"

# define BUFFER_SIZE 1024
# define RULES_MIN_LEN 4
# define RULES_CHARSET_LEN 3

t_run   *init_size(t_run *run_addr);
t_run   *clean_size(t_run *run_addr);
t_run   *set_size(t_run *run_addr, t_size size);
t_run   *init_rules(t_run *run_addr);
t_run   *clean_rules(t_run *run_addr);
t_run   *set_rules(t_run *run_addr, t_rules rules);
t_run   *init_cell(t_run *run_addr);
t_run   *clean_cell(t_run *run_addr);
t_run   *set_cell(t_run *run_addr, t_cell cell);
t_run   *init_solution(t_run *run_addr);
t_run   *clean_solution(t_run *run_addr);
t_run   *set_last_best(t_run *run_addr, t_cell cell);
t_run   *set_solution_table(t_run *run_addr, t_cell cell);
t_run   *init_solution_table(t_run *run_addr);
t_run   *init_file_content(t_run *run_addr);
t_run   *clean_file_content(t_run *run_addr);
t_run   *set_file_content(t_run *run_addr, t_file_content content);
t_run   *init_map(t_run *run_addr);
t_run   *clean_map(t_run *run_addr);
t_run   *set_map(t_run *run_addr, t_board_c map);
t_run   init_run(t_file_content content);
t_run   *clean_run(t_run *run_addr);
t_run	from_file_to_run(t_filepath path);
t_run	*from_files_to_runs(t_filepath *paths, int size);
t_run	from_stdin_to_run(t_filepath path);
t_run	*from_stdin_to_runs();

#endif
