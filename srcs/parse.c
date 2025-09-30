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
	t_rules	rules;
	char	*height_str;

	if (!check_rules(str))
		return (clean_run(run));
	height_str = ft_strndup(str, ft_strlen(str) - 3);
	if (!height_str)
		return (clean_run(run));
	rules.size.height = atoi(height_str);
	ft_free_str(&height_str);
	if (rules.size.height == 0)
		return (clean_run(run));
	rules.empty = str[ft_strlen(str) - 3];
	rules.obstacle = str[ft_strlen(str) - 2];
	rules.filled = str[ft_strlen(str) - 1];
	set_rules(run, rules);
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
	run->rules.size.width = ft_strlen(board[0]);
	charset[0] = run->rules.empty;
	charset[1] = run->rules.obstacle;
	charset[2] = '\0';
	while(board[i])
	{
		if (ft_strlen(board[i]) != run->rules.size.width)
			return (0);
		j = 0;
		while (board[i][j])
		{
			if (!is_in_charset(board[i][j++], charset))
				return (0);
		}	
	}
	if (i + 1 != run->rules.size.height)
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
	t_rules	rules;

	if (run->status == ERROR)
		return (run);
	lines = ft_split(run->content, "\n");
	if (!lines)
		return (clean_run(run));
	run = get_rules(lines[0], run);
	if (run->status == ERROR)
	{
		ft_free_str_list(&lines, -1);
		return (run);
	}
	if (!check_board(lines + 1, &run))
	{
		ft_free_str_list(&lines, -1);
		return (clean_run(run));
	}
	create_map(run, lines);
	return (run);
}
