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

void	ft_read_file(const t_filepath p, t_read_content *content);
void	ft_read_stdin(const t_filepath _, t_read_content *content);
void	first_read(t_read_content *content, char *buffer, int read_count);
void	read_realloc(t_read_content *content, char *buffer, int read_count);

#endif