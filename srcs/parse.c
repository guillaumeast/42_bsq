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

#include "bsq.h"

char	check_rules(char *str)
{
	printf("check_rules |%s|\n", str);
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		if (i >= len - 3)
		{
			j = 1;
			while (str[i + j])
			{
				if (str[i] == str[i + j++])
					return (0);
			}
		}
		i++;
	}
	return (1);
}

t_run	*get_rules(char *str, t_run *run)
{
	printf("In get rules\n");

	t_rules	rules;
	char	*height_str;
	int		len;

	print_debug_status(*run);
	if (!check_rules(str))
	{
		printf("checked rules failed\n");
		return (clean_run(run));
	}
	print_debug_status(*run);
	height_str = ft_strndup(str, len - 3);
	print_debug_status(*run);
	if (!height_str)
		return (clean_run(run));
	print_debug_status(*run);
	rules.size.height = atoi(height_str);
	ft_free_str(&height_str);
	print_debug_status(*run);
	if (rules.size.height == 0)
		return (clean_run(run));
	print_debug_status(*run);
	rules.empty = str[len - 3];
	rules.obstacle = str[len - 2];
	rules.filled = str[len - 1];
	print_debug_status(*run);
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
		i++;
	}
	if (i != run->rules.size.height)
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

	print_debug_status(*run);
	if (run->status == ERROR)
		return (run);
	print_debug_status(*run);
	printf("printf split\n");
	lines = ft_split(run->content, "\n");
	print_board_1(lines);
	print_debug_status(*run);
	if (!lines)
		return (clean_run(run));
	run = get_rules(lines[0], run);
	// this one is set to ERROR
	print_debug_status(*run);
	if (run->status == ERROR)
	{
		ft_free_str_list(&lines, -1);
		return (run);
	}
	if (!check_board(lines + 1, run))
	{
		ft_free_str_list(&lines, -1);
		return (clean_run(run));
	}
	print_debug_status(*run);
	create_map(run, lines);
	return (run);
}