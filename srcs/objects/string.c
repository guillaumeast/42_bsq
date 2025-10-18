#include "bsq.h"

static t_str	*str_grow(t_str *str, size_t cap_need);

t_str	*str_new(size_t initial_cap)
{
	t_str	*str;

	str = malloc(sizeof(t_str));
	if (!str)
		return (NULL);
	if (initial_cap > 0)
	{
		str->str = malloc(initial_cap);
		if (!str->str)
		{
			free(str);
			return (NULL);
		}
		str->str[0] = '\0';
	}
	str->cap = initial_cap;
	str->len = 0;
	return (str);
}

t_str	*str_append_buf(t_str **dst, const char *buffer, size_t n)
{
	size_t	dst_len;
	size_t	i;

	dst_len = (*dst)->len;
	if (!str_grow(*dst, dst_len + n + 1))
		return (NULL);
	i = 0;
	while (i < n)
	{
		(*dst)->str[dst_len + i] = buffer[i];
		i++;
	}
	(*dst)->str[dst_len + i] = '\0';
	(*dst)->len = dst_len + i;
	return (*dst);
}

t_str	*str_append(t_str **dst, const t_str *src, size_t n)
{
	size_t	dst_len;
	size_t	i;

	dst_len = (*dst)->len;
	if (!str_grow(*dst, dst_len + n + 1))
		return (NULL);
	i = 0;
	while (i < n)
	{
		(*dst)->str[dst_len + i] = src->str[i];
		i++;
	}
	(*dst)->str[dst_len + i] = '\0';
	(*dst)->len = dst_len + i;
	return (*dst);
}

t_str	*str_free(t_str **str)
{
	free((*str)->str);
	free(*str);
	*str = NULL;
	return (NULL);
}

static t_str	*str_grow(t_str *str, size_t cap_need)
{
	char	*new_content;
	size_t	new_cap;
	size_t	i;

	if (cap_need <= str->cap)
		return (str);
	new_cap = str->cap * 2;
	while (new_cap < cap_need)
		new_cap *= 2;
	new_content = malloc(new_cap);
	if (!new_content)
		return (str_free(&str));
	str->cap = new_cap;
	i = 0;
	while (i < str->len)
	{
		new_content[i] = str->str[i];
		i++;
	}
	new_content[i] = '\0';
	free(str->str);
	str->str = new_content;
	return (str);
}
