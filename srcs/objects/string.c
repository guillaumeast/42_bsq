#include "bsq.h"

void	init_str(t_str *str)
{
	str->p = NULL;
	str->row_width = 0;
	str->row_len = 0;
	str->str_len = 0;
}

void	set_str(t_str *str, char *p, size_t row_width, size_t str_len)
{
	str->p = p;
	str->row_width = row_width;
	str->row_len = row_width + 1;
	str->str_len = str_len;
}
