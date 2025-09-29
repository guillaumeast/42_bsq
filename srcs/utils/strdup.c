/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:31:15 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 17:03:39 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		++i;
	}
}
