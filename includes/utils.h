/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:57:41 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 15:17:21 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <unistd.h>

void	ft_free_str(char **str_addr);
void    ft_putstr(char *str);
void	ft_free_board(char ***board_addr, int rows);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, int size);
char	*ft_strcpycat(char *prev, char *new, int size);
char	*ft_strncat(char *dest, char *src, int size);
char	**ft_split(char *str, char *charset);

#endif
