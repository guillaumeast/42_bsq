/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:57:41 by adouieb           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/09/29 19:19:59 by gastesan         ###   ########.fr       */
=======
/*   Updated: 2025/09/29 19:44:21 by adouieb          ###   ########.fr       */
>>>>>>> origin/Alexander
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <unistd.h>

<<<<<<< HEAD
void	ft_free_rules(t_rules **rules);
=======
char	is_whitespace(char c);
int		ft_atoi(char *str);

>>>>>>> origin/Alexander
void	ft_free_str(char **str_addr);
void	ft_str_list(char ***str_arr_addr, int n);

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
