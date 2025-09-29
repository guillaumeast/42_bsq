/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:30 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:35:16 by gastesan         ###   ########.fr       */
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
char get_rules(char *str, t_rules **rules)
{
	t_rules	*rules;
	int		size;
	char	*number;

	if (!check_rules)
		return (0);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (0);
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
	return (rules);
}

t_exercice	parse(t_exercice)
{
	char	**lines;
	int		i;

	lines = ft_split(input, "\n");
	if (!lines)
		return (NULL);
	if (!get_rules(lines[0], &rules))
	{
		ft_free_list(&lines, -1)
		return (NULL);
	}
	i = 1;
	// check each line validity
	// return 0 + struct NULL if fail || 1 + struct if success
}
