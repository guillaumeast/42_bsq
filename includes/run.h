/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:49:00 by gastesan          #+#    #+#             */
/*   Updated: 2025/10/01 12:49:02 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_H
# define RUN_H

#include "types.h"

t_run	init_run(t_file_content content);
t_run	*clean_run(t_run *run_addr);

t_run	*init_map(t_run *run_addr);
t_run	*clean_map(t_run *run_addr);

t_run	*init_file_content(t_run *run_addr);
t_run	*clean_file_content(t_run *run_addr);

#endif
