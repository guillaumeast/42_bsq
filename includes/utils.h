/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:57:41 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 20:33:44 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <unistd.h>

void	ft_free_rules(t_rules **rules);
void	ft_free_str(char **str_addr);
void	ft_str_list(char ***str_arr_addr, int n);

char	is_whitespace(char c);
int		ft_atoi(char *str);

void	ft_putstr(char *str);

char	is_in_charset(char c, char *charset);
int		word_count(char *str, char *charset);
void	ft_multistrdup(char **result, char* str, char *charset);
char	**ft_split(char *str, char *charset);

char	*ft_strcpycat(char *prev, char *new, int size);

int		ft_strlen(char *str);

char	*ft_strncat(char *dest, char *src, int size);

char	*ft_strncpy(char *dest, char *src, int size);

char	*ft_strndup(char *str, int size);

#endif
