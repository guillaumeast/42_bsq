/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:30 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 00:29:57 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_run	*on_parse_fail(t_run *run)
{
	ft_free_str(run->content);
	run->content = NULL;
	run->rules.height = 0;
	run->rules.width = 0;
	run->rules.empty = '\0';
	run->rules.obstacle = '\0';
	run->rules.filled = '\0';
	if (run->map)
	{
		ft_free_str_list(&run->map, -1);
		run->map = NULL;
	}
	run->status = ERROR;
	return (run);
}

char	check_rules(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) < 4)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32)
			return (0);
		j = 1;
		while (str[i + j])
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_run	*get_rules(char *str, t_run *run)
{
	char	*height_str;

	if (!check_rules(str))
	{
		on_parse_fail(run);
		return (run);
	}
	height_str = ft_strndup(str, ft_strlen(str) - 3);
	if (!height_str)
	{
		on_parse_fail(run);
		return (run);
	}
	run->rules.height = atoi(height_str);
	ft_free_str(&height_str);
	if (run->rules.height == 0)
	{
		on_parse_fail(run);
		return (run);
	}
	run->rules.empty = str[ft_strlen(str) - 3];
	run->rules.obstacle = str[ft_strlen(str) - 2];
	run->rules.filled = str[ft_strlen(str) - 1];
	return (run);
}

char	check_board(t_board_c board, t_run *run)
{
	int		i;
	int		j;
	char	charset[3];
	
	if (!board[0] || !board[0][0])
		return (0);
	i = 0;
	run->rules.width = ft_strlen(board[0]);
	charset[0] = run->rules.empty;
	charset[1] = run->rules.obstacle;
	charset[2] = '\0';
	while(board[i])
	{
		if (ft_strlen(board[i]) != run->rules.width)
			return (0);
		j = 0;
		while (board[i][j])
		{
			if (!is_in_charset(board[i][j++], charset))
				return (0);
		}	
	}
	if (i + 1 != run->rules.height)
		return (0);
	return (1);
}

t_run	*create_map(t_run *run, char **lines)
{
	int	i;

	free(lines[0]);
	i = 1;
	while (lines[i])
	{
		lines[i - 1] = lines[i];
		i++;
	}
	lines[i - 1] = NULL;
	run->map = lines;
	return (run);
}

t_run	*parse(t_run *run)
{
	char	**lines;

	if (run->status == ERROR)
		return (run);
	lines = ft_split(run->content, "\n");
	if (!lines)
	{
		on_parse_fail(run);
		return (run);
	}
	run = get_rules(lines[0], run);
	if (run->status == ERROR)
	{
		ft_free_str_list(&lines, -1);
		return (run);
	}
	if (!check_board(lines + 1, &run))
	{
		ft_free_str_list(&lines, -1);
		on_parse_fail(run);
		return (run);
	}
	create_map(run, lines);
	ft_free_str_list(&lines, -1);
	return (run);
}

/*
#include <stdio.h>
// ccc srcs/parse.c srcs/utils/free.c srcs/utils/strlen.c srcs/utils/split.c srcs/utils/strndup.c
int	main(void)
{
	t_run 	*run;
	int		i;

	run->content = "3.ox\n.....\n..o..\nooooo";
	run = parse(&run);
	printf("Content = %s\n", run->content);
	printf("height = %d | width = %d | empty = %c | obstacle = %c | filled = %c\n", run->rules.height, run->rules.width, run->rules.empty, run->rules.obstacle, run->rules.filled);
	printf("Status = %u\n", run->status);
	printf("Map:\n");
	i = 0;
	while (run->map[i])
	{
		printf("%s\n", run->map[i]);
		i++;
	}
	return (0);
}
*/