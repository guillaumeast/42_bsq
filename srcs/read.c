/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:33:01 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 23:29:08 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	first_read(t_read_content *content, char *buffer, int read_count)
{
	content->size = (BUFFER_SIZE + 1);
	content->content = malloc(sizeof(char) * content->size);
	ft_strncpy(content->content, NULL, content->byte_count);
	ft_strncat(content->content, buffer, read_count);
}

void	read_realloc(t_read_content *content, char *buffer, int read_count)
{
	t_file_content	temp;

	content->size *= 2;
	temp = content->content;
	content->content = malloc(sizeof(char) * content->size);
	ft_strncpy(content->content, temp, content->byte_count);
	ft_strncat(content->content, buffer, read_count);
	ft_free_str(&temp);
}

void	ft_read_file(const t_filepath p, t_read_content *content)
{
	int		read_bytes_count;
	char	read_buffer[BUFFER_SIZE];

	read_bytes_count = -1;
	content->fd = open(p, O_RDONLY);
	if (content->fd == -1)
		return ;
	while (read_bytes_count != 0)
	{
		read_bytes_count = read(content->fd, read_buffer, BUFFER_SIZE);
		if (read_bytes_count == -1)
			return (ft_free_str(&(content->content)));
		else if (read_bytes_count == 0)
			return ;
		if (content->size == 0)
			first_read(content, read_buffer, read_bytes_count);
		else if (content->byte_count + read_bytes_count >= content->size)
			read_realloc(content, read_buffer, read_bytes_count);
		else
			ft_strncat(content->content, read_buffer, read_bytes_count);
		content->byte_count += read_bytes_count;
	}
}

void	ft_read_stdin(const t_filepath _, t_read_content *content)
{
	int				read_bytes_count;
	char			read_buffer[BUFFER_SIZE];
	t_file_content	temp;

	(void)_;
	(1 && (read_bytes_count = -1), (temp = NULL));
	while (read_bytes_count != 0)
	{
		read_bytes_count = read(STDIN_FILENO, read_buffer, BUFFER_SIZE);
		if (read_bytes_count == -1)
			return (ft_free_str(&(content->content)));
		else if (read_bytes_count == 0)
			return ;
		if (content->size == 0)
			first_read(content, read_buffer, read_bytes_count);
		else if (content->byte_count + read_bytes_count >= content->size)
			read_realloc(content, read_buffer, read_bytes_count);
		else
			ft_strncat(content->content, read_buffer, read_bytes_count);
		content->byte_count += read_bytes_count;
	}
}
