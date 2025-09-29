/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:30 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 20:11:12 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse.h"

// Caller must free t_rules
t_rules	*get_rules(char *str)
{
	t_rules	*rules;
	int		size;
	char	*number;

	if (ft_strlen(str) < 4)
		return (NULL);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	size = ft_strlen(str);
	number = strndup(str, size - 3);
	if (!number)
	{
		ft_free_rules(&rules);
		return (NULL);
	}
	rules->size = atoi(number);
	free(number);
	rules->empty = str[size - 3];
	rules->obstacle = str[size - 2];
	rules->filled = str[size - 1];
	return (rules);
}

char	**parse(t_rules *rules, char *input)
{
	char	**lines;
	int		i;

	lines = ft_split(input, "\n");
	if (!lines)
		return (NULL);
	rules = get_rules(lines[0]);
	if (!rules)
	{
		// TODO : free lines
		return (NULL);
	}
	// check each line validity
	// return 0 + struct NULL if fail || 1 + struct if success
}
