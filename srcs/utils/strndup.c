/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:31:15 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 17:26:56 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*result;

	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size && str[i] != '\0')
	{
		result[i] = str[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
