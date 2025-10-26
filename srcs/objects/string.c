#include "bsq.h"

// Creates a new `t_str` structure with the given string and length
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

// Frees a `t_str` structure and sets its pointer to `NULL`
t_str	*str_free(t_str **str)
{
	if (!str || !*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}
