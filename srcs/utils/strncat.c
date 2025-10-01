/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:17:36 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 14:50:43 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strncat(char *dest, char *src, int size)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	printf("size = %d\n", size);
	printf("dest_len = %d\n", dest_len);
	printf("src[i] = %c\n", src[i]);
	while (src[i] != '\0' && i < size)
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
