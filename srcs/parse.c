/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:30 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 19:00:18 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse.h"

char	check_rules_format(char *str)
{
	if (ft_strlen(str) < 4)
		return (0);
	if (str[0] < '0' || str[0] > '9')
		return (0);
	while (str[0] >= '0' && str[0] <= '9')
		str++;
	if (ft_strlen(str) != 3)
		return (0);
	while (str[0] != '\0')
	{
		if (str[0] < 32 || str[0] > 126)
			return (0);
		str++;
	}
	return (1);
}

// Caller must free t_rules
t_rules	*get_rules(char *str)
{
	t_rules	*rules;

	if (!check_rules_format)
		return (NULL);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	rules->size = atoi(str);
	while (is_space(str[0]))
		str++;
	while (str[0] == '-' || str[0] == '+')
		str++;
	while (str[0] >= '0' && str[0] <= '9')
		str++;
	rules->empty = str[0];
	rules->obstacle = str[1];
	rules->filled = str[2];
	return (rules);
}
strndup str (size - 3)

char	**parse(t_rules *rules, char *input)
{
	char	**lines;
	t_rules	*rules;
	int		i;

	lines = ft_split(input, "\n");
	if (!splitted)
		return (NULL);
	if (!check_rules(lines[0]))
		return (NULL);
	rules = get_rules(lines[0]);
	// check each line validity
	// return 0 + struct NULL if fail || 1 + struct if success
}
