/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:57:41 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 21:59:58 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(char *str);
char	is_whitespace(char c);

void	ft_free_str(char **str_addr);
void	ft_close(int file_descriptor);
void	ft_free_int_list(int ***str_arr_addr, int n);
void	ft_free_str_list(char ***str_arr_addr, int n);
void	ft_free_and_close(int file_descriptor, t_read_content *content);

t_run	*run_to_run_map(t_run *instance, int size, t_run *(*act)(t_run *));
t_run	*file_to_run_map(t_filepath *paths, int size, t_run (*act)(t_filepath));

void	ft_putstr(char *str);

char	is_in_charset(char c, char *charset);
int		word_count(char *str, char *charset);
char	**ft_split(char *str, char *charset);
void	ft_multistrdup(char **result, char *str, char *charset);

int		ft_strlen(char *str);

char	*ft_strncat(char *dest, char *src, int size);

char	*ft_strncpy(char *dest, char *src, int size);

char	*ft_strndup(char *str, int size);

#endif
