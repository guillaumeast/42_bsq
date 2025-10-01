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
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	if (len < RULES_MIN_LEN)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		if (i >= len - RULES_CHARSET_LEN)
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
	char	*height_str;
	int		len;

	if (!check_rules(str))
		return (clean_run(run));
	len = ft_strlen(str);
	height_str = ft_strndup(str, len - RULES_CHARSET_LEN);
	if (!height_str)
		return (clean_run(run));
	run->rules.size.height = atoi(height_str);
	ft_free_str(&height_str);
	if (run->rules.size.height == 0)
	{
		printf("---> |X| Height = 0\n");
		return (clean_run(run));
	}
	run->rules.empty = str[len - RULES_CHARSET_LEN];
	run->rules.obstacle = str[len - (RULES_CHARSET_LEN - 1)];
	run->rules.filled = str[len - (RULES_CHARSET_LEN - 2)];
	return (run);
}

char	check_board(t_board_c board, t_run *run)
{
	int		i;
	int		j;
	char	charset[3];

	if (!board[0] || !board[0][0])
	{
		printf("---> |X| !board[0] = '%s' || !board[0][0] = '%c'\n", board[0], board[0][0]);
		return (0);
	}
	i = 0;
	run->rules.size.width = ft_strlen(board[0]);
	charset[0] = run->rules.empty;
	charset[1] = run->rules.obstacle;
	charset[2] = '\0';
	while (board[i])
	{
		if (ft_strlen(board[i]) != run->rules.size.width)
		{
			printf("---> |X| Wrong width (%d vs %d)\n", ft_strlen(board[i]), run->rules.size.width);
			return (0);
		}
		j = 0;
		while (board[i][j])
		{
			if (!is_in_charset(board[i][j++], charset))
			{
				j--;
				printf("---> |X| Wrong char (%c vs %d)\n", board[i][j], run->rules.size.width);
				j++;
				return (0);
			}
		}
		i++;
	}
	if (i != run->rules.size.height)
		printf("---> |X| Wrong height (%d vs %d)\n", i, run->rules.size.height);
	return (i == run->rules.size.height);
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
	// Check run->content[last] == '\n'
	lines = ft_split(run->content, "\n");
	if (!lines)
		return (clean_run(run));
	run = get_rules(lines[0], run);
	if (run->status == ERROR)
	{
		printf("---> check_rules failed\n");
		ft_free_str_list(&lines, -1);
		return (run);
	}
	if (!check_board(lines + 1, run))
	{
		printf("---> check_board failed\n");
		ft_free_str_list(&lines, -1);
		return (clean_run(run));
	}
	printf("---> check passed\n");
	create_map(run, lines);
	return (run);
}
