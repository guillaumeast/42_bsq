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

#include "bsq.h"

int	ft_fast_atoi_n(t_str *str, size_t n)
{
	const unsigned char *p;
	const unsigned char *end;
	int result = 0;

	p = (const unsigned char *)str->content;
	end = p + n;
	while (p < end)
	{
		if ((unsigned)(*p - '0') <= 9)
			result = result * 10 + (*p++ - '0');
		else
			return (-1);
	}
	return (result);
}
