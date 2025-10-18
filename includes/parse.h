#ifndef PARSE_H
# define PARSE_H

# include "bsq.h"

t_bool	parse(t_run *run, t_str *input);
t_bool	parse_rules(t_str *input, t_rules *r);

#endif
