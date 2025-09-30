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
	int	len;

	printf("START - Check rules |%s|\n", str);
	len = ft_strlen(str);
	if (len < 4)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		if (i >= len - 3) // Check doublons only for last 3 chars
		{
			j = 1;
			while (str[i + j])
			{
				if (str[i] == str[i + j])
					return (0);
				j++;
			}
		}
		i++;
	}
	printf("END - Check rules |%s|\n", str);
	return (1);
}

t_run	*get_rules(char *str, t_run *run)
{
	t_rules	rules;
	char	*height_str;

	printf("get_rules - START |%s|\n", str);
	if (!check_rules(str))
		return (clean_run(run));
	printf("get_rules - check_rules ended |%s|\n", str);
	height_str = ft_strndup(str, ft_strlen(str) - 3);
	printf("get_rules - ft_strndup ended |%s|\n", str);
	if (!height_str)
		return (clean_run(run));
	rules.size.height = atoi(height_str);
	printf("get_rules - atoi ended |%s|\n", str);
	ft_free_str(&height_str);
	printf("get_rules - ft_free_str ended |%s|\n", str);
	if (rules.size.height == 0)
		return (clean_run(run));
	rules.empty = str[ft_strlen(str) - 3];
	rules.obstacle = str[ft_strlen(str) - 2];
	rules.filled = str[ft_strlen(str) - 1];
	printf("get_rules - before set_rules |%s|\n", str);
	set_rules(run, rules);
	printf("get_rules - after set_rules |%s|\n", str);
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

	if (run->status == ERROR)
		return (run);
	lines = ft_split(run->content, "\n");
	if (!lines)
		return (clean_run(run));
	printf("Before get_rules");
	run = get_rules(lines[0], run);
	printf("After get_rules");
	if (run->status == ERROR)
	{
		ft_free_str_list(&lines, -1);
		return (run);
	}
	printf("Before check_board");
	if (!check_board(lines + 1, run))
	{
		ft_free_str_list(&lines, -1);
		return (clean_run(run));
	}
	printf("After check_board");
	create_map(run, lines);
	printf("After create_map");
	return (run);
}
