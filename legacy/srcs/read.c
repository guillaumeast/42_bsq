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

char	is_valid(t_read_content *content)
{
	int		i;
	char	*str;
	char	is_valid;

	i = 0;
	str = NULL;
	is_valid = 1;
	while (i < content->byte_count)
	{
		if (content->content[i] == '\n')
		{
			str = ft_strndup(content->content, i);
			is_valid = check_rules(str);
			if (is_valid == 0)
				ft_free_str(&(content->content));
			ft_free_str(&str);
			return (is_valid);
		}
		++i;
	}
	return (is_valid);
}

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
	ft_fill_buffer(read_buffer, BUFFER_SIZE);
	if (content->fd == -1)
		return (ft_close(content->fd));
	while (read_bytes_count != 0)
	{
		read_bytes_count = read(content->fd, read_buffer, BUFFER_SIZE);
		if (read_bytes_count == -1)
			return (ft_free_and_close(content->fd, content));
		else if (read_bytes_count == 0)
			return (ft_close(content->fd));
		if (content->size == 0)
			first_read(content, read_buffer, read_bytes_count);
		else if (content->byte_count + read_bytes_count >= content->size)
			read_realloc(content, read_buffer, read_bytes_count);
		else
			ft_strncat(content->content, read_buffer, read_bytes_count);
		content->byte_count += read_bytes_count;
	}
	ft_close(content->fd);
}

void	ft_read_stdin(const t_filepath _, t_read_content *content)
{
	int				read_bytes_count;
	char			read_buffer[BUFFER_SIZE];

	(void)_;
	ft_fill_buffer(read_buffer, BUFFER_SIZE);
	read_bytes_count = -1;
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
		if (content->byte_count >= TIMEOUT || !is_valid(content))
			return ;
	}
}
