/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:55:25 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 19:39:30 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	is_whitespace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]) == 1 && str[i] != '\0')
		++i;
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		++i;
	}
	return (result * sign);
}
