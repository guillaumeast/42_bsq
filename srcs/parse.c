/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:30 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 00:03:27 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse.h"

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

// Caller must free t_rules
t_run	get_rules(char *str, t_run run)
{
	int		size;
	char	*number;

	if (!check_rules)
	{
		// free + null + error
		return (0);
	}
	rules = malloc(sizeof(t_rules));
	if (!rules)
	{
		// free + null + error
		return (0);
	}
	size = ft_strlen(str);
	number = strndup(str, size - 3);
	if (!number)
	{
		ft_free_rules(&rules);
		return (0);
	}
	rules->size = atoi(number);
	if (rules->size == 0)
	{
		ft_free_str(&number);
		return (0);
	}
	ft_free_str(&number);
	rules->empty = str[size - 3];
	rules->obstacle = str[size - 2];
	rules->filled = str[size - 1];
	return (1);
}

char	check_board(char **board, t_rules rules)
{
	int		i;
	int		len;
	char	*charset;
	
	// Au moins une ligne d'au moins une case
	if (!board[0] || !board[0][0])
		return (0)
	i = 0;
	len = ft_strlen(board[0]);
	charset[0] = rules.empty;
	charset[1] = rules.obstacle;
	charset[2] = '\0';
	while(board[i])
	{
		// Toutes les lignes ont la meme taille
		if (ft_strlen(board[i] != len))
			return (0);
		// Contient uniquement les caracteres du charset
		j = 0;
		while (board[i][j])
		{
			if (!is_in_charset(board[i][j], charset))
				return (0);
			j++;
		}	
	}
}

t_run	parse(t_run run)
{
	char	**lines;

	lines = ft_split(input, "\n");
	if (!lines)
	{
		// Set run to NULL/ERR
		return (run);
	}
	if (!get_rules(lines[0], rune->&rules))
	{
		ft_free_str_list(&lines, -1)
		// Set run to NULL/ERR
		return (run);
	}
	if (!check_board(lines + 1))
	{
		// Set run to NULL/ERR
		return (run);
	}
	// check each line validity
	// create board (copy pointers)
	// return 0 + struct NULL if fail || 1 + struct if success
}
