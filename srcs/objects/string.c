#include "bsq.h"

t_str	*str_new(char *str, size_t len)
{
	t_str	*res;

	res = malloc(sizeof(t_str));
	if (!res)
		return (NULL);
	res->str = str;
	res->len = len;
	return (res);
}

t_str	*str_free(t_str **str)
{
	free((*str)->str);
	free(*str);
	*str = NULL;
	return (NULL);
}
