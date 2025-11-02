#ifndef RUN_H
# define RUN_H

# include "bsq.h"

t_run	*run_new();
void	run_add_rules(t_run **run);
t_bool dp_init(t_run *run, size_t width);
void	run_free(t_run **run);

#endif
