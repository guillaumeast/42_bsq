#ifndef FT_STR
# define FT_STR

# include "bsq.h"

t_str	*str_new(size_t initial_cap);
t_str	*str_append_buf(t_str **dst, const char *buffer, size_t n);
t_str	*str_append(t_str **dst, const t_str *src, size_t n);
t_str	*str_free(t_str **str);

#endif
