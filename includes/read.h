/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:49:51 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:06:22 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

# define BUFFER_SIZE 1024

t_file_content	ft_read_file(const t_filepath	pathname);
t_file_content	ft_read_stdin();

#endif
