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

#include "read.h"
#include "utils.h"

t_file_content	ft_read_file(const t_filepath pathname)
{
	t_file_content	content;
	int				file_descriptor;
	int				read_bytes_c;
	char			buffer[BUFFER_SIZE];

	(1 && (content = NULL), (read_bytes_c = -1));
	file_descriptor = open(pathname, O_RDONLY);
	if (file_descriptor == -1)
		return (NULL);
	while (read_bytes_c != 0)
	{
		read_bytes_c = read(file_descriptor, buffer, BUFFER_SIZE);
		if (read_bytes_c == -1 && content != NULL)
		{
			ft_free_str(&content);
			return (NULL);
		}
		else if (read_bytes_c != 0)
		{
			content = ft_strcpycat(content, buffer, read_bytes_c);
			if (content == NULL)
				return (NULL);
		}
	}
	return (content);
}

t_file_content	ft_read_stdin(const t_filepath _)
{
	t_file_content  content;
	int				read_bytes_c;
    char            buffer[BUFFER_SIZE];

	content = NULL;
	read_bytes_c = -1;
	if (_[0] != '\0')
		return (NULL);
	while (read_bytes_c != 0)
	{
		read_bytes_c = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (read_bytes_c == -1 && content != NULL)
        {
            ft_free_str(&content);
            return (NULL);
        }
        else if (read_bytes_c != 0)
        {
            content = ft_strcpycat(content, buffer, read_bytes_c);
            if (content == NULL)
                return (NULL);
        }
	}
	return (content);
}
