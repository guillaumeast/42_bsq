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

#include "../includes/bsq.h"

void	ft_read_file(const t_filepath p, t_read_content *content)
{
	printf("In read");

	int				read_bytes_count;
	char			read_buffer[BUFFER_SIZE];
	t_file_content	temp;

	(1 && (read_bytes_count = -1), (temp = NULL));
	content->fd = open(p, O_RDONLY);
	if (content->fd == -1)
		return ;
	printf("open file and get fd %d\n", content->fd);
	while (read_bytes_count != 0)
	{
		read_bytes_count = read(content->fd, read_buffer, BUFFER_SIZE);
		printf("Read %d bytes from files\n", read_bytes_count);
		if (read_bytes_count == -1)
			return (ft_free_str(&(content->content)));
		else if (read_bytes_count == 0)
			return ;
		if (content->size == 0)
		{
			content->size = (BUFFER_SIZE + 1);
			printf("Malloc for the first time with %d size\n", content->size);
			content->content = malloc(sizeof(char) * content->size);
			printf("Allocation returned pointer %p\n", content->content);
		}
		else if (content->byte_count + read_bytes_count >= content->size)
		{
			content->size *= 2;
			printf("Malloc again because content is too small with %d size\n", content->size);
			temp = content->content;
			printf("Store previous content pointer %p into temp\n", content->content);
			content->content = malloc(sizeof(char) * content->size);
			printf("New allocation content returned pointer %p\n", content->content);
		}
		ft_strncpy(content->content, temp, content->byte_count);
		ft_strncat(content->content, read_buffer, read_bytes_count);
		ft_free_str(&temp);
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
		{
			content->size = (BUFFER_SIZE + 1);
			content->content = malloc(sizeof(char) * content->size);
		}
		else if (content->byte_count + read_bytes_count >= content->size)
		{
			content->size *= 2;
			temp = content->content;
			content->content = malloc(sizeof(char) * content->size);
		}
		ft_strncpy(content->content, temp, content->byte_count);
		ft_strncat(content->content, read_buffer, read_bytes_count);
		ft_free_str(&temp);
		content->byte_count += read_bytes_count;
	}
}
