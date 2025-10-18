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

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "types.h"
# include "utils.h"
# include "run.h"
# include "read.h"
# include "parse.h"
# include "resolve.h"
# include "print.h"

# define BUFFER_SIZE 1000000
# define TIMEOUT 63569920
# define RULES_MIN_LEN 4
# define RULES_CHARSET_LEN 3

t_run	*from_stdin_to_runs(void);
t_run	from_file_to_run(t_filepath path);
t_run	from_stdin_to_run(t_filepath path);
t_run	*from_files_to_runs(t_filepath *paths, int size);

#endif
