#ifndef PARSE_H
# define PARSE_H

# include "bsq.h"

void	parse_rules(t_run **run, char *input, size_t input_len, t_rules *r);
void	parse_map(t_run **run);

#endif
