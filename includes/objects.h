#ifndef OBJECTS_H
# define OBJECTS_H

# include "bsq.h"

void	init_buffer(t_buffer *buffer);

void	init_str(t_str *str);
void	set_str(t_str *str, char *p, size_t row_width, size_t str_len);

void	init_rules(t_rules *rules);

void	init_dp(t_dp *dp);

void	init_bsq(t_bsq *bsq);

t_run	*run_new();
void	run_free(t_run **run);

#endif
