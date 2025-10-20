#ifndef BSQ_STR
# define BSQ_STR

# include "bsq.h"

t_str	*str_new(char *str, size_t len, size_t cap);
t_str	*str_grow(t_str **str, size_t cap_need);
t_str	*str_free(t_str **str);

#endif
