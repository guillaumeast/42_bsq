/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:47:18 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:05:01 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>
#include "includes/utils.h"

typedef char** t_board;

typedef struct rules
{
	int		size;
	char	empty;
	char	obstacle;
	char	filled;
}	t_rules;

#endif
