#ifndef PARSE_RULES_H
# define PARSE_RULES_H

# include "bsq.h"

# define RULES_MIN_LEN 4
# define RULES_CHARSET_LEN 3

void	parse_rules(t_run **run, char *input, size_t input_len, t_rules *r);

#endif
