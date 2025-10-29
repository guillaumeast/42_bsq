#include "bsq.h"

void	init_buffer(t_buffer *buffer)
{
	buffer->data = NULL;
	buffer->len = 0;
	buffer->cap = 0;
}
