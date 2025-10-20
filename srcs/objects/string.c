#include "bsq.h"

t_str	*str_new(char *str, size_t len, size_t cap)
{
	t_str	*res;

	res = malloc(sizeof(t_str));
	if (!res)
		return (NULL);
	res->str = str;
	res->len = len;
	res->cap = cap;
	return (res);
}

t_str	*str_free(t_str **str)
{
	if (!str || !*str)
		return (NULL);
	if ((*str)->str)
	{
		free((*str)->str);
		(*str)->str = NULL;
	}
	free(*str);
	*str = NULL;
	return (NULL);
}
