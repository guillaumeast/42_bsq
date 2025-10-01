/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:56:22 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/29 18:47:08 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int		i;
	int		word_count;
	char	in_word;

	i = 0;
	word_count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (is_in_charset(str[i], charset) == 0 && in_word == 0)
		{
			in_word = 1;
			++word_count;
		}
		else if (is_in_charset(str[i], charset) == 1 && in_word == 1)
			in_word = 0;
		++i;
	}
	return (word_count);
}

void	ft_multistrdup(char **result, char* str, char *charset)
{
	int		i;
	int		start;
	int		result_i;
	char	in_word;

	i = 0;
	result_i = 0;
	in_word = 0;
	while (result != NULL && str[i] != '\0')
	{
		if (is_in_charset(str[i], charset) == 0 && in_word == 0)
		{
			start = i;
			while (is_in_charset(str[i], charset) == 0 && str[i] != '\0')
				++i;
			result[result_i] = ft_strndup(str + start, i - start);
			if (result[result_i] == NULL)
				ft_free_str_list(&result, result_i);
			++result_i;
		}
		else if (is_in_charset(str[i], charset) == 1 && in_word == 1)
			in_word = 0;
		++i;
	}
	result[result_i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_c;
	char	**result;

	i = 0;
	word_c = word_count(str, charset);
	result = malloc(sizeof(char *) * (word_c + 1));
	if (result == NULL)
		return (NULL);
	ft_multistrdup(result, str, charset);
	return (result);
}
