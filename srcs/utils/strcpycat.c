/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpycat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:17:43 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 14:55:45 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

char	*ft_strcpycat(char *prev, char *new, int size)
{
	char	*result;

	if (size == 0)
		return (prev);
	if (prev == NULL)
	{
		result = malloc(sizeof(char) * (size + 1));
		if (result == NULL)
			return (NULL);
		ft_strncpy(result, new, size);
	}
	else
	{
		result = malloc(sizeof(char) * (ft_strlen(prev) + size + 1));
		if (result == NULL)
        {
            ft_free_str(&prev);
            return (NULL);
        }
		ft_strncpy(result, prev, ft_strlen(prev));
		ft_strncat(result, new, size);
		ft_free_str(&prev);
	}
	return (result);
}
