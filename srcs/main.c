/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 14:56:16 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int	main(int argc, char **argv)
{
	printf("number args %d\n", argc);
	printf("argv %p\n", argv);

	char	*str = ft_read_file("/home/adouieb/Documents/Piscine/BSQ/tests/basic_test");

	printf("%s\n", str);
	ft_free_str(&str);
}
