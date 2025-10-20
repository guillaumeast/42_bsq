#ifndef RUN_H
# define RUN_H

# include "bsq.h"

t_run	*run_new();
t_run	*run_add_input(t_run *run, t_str *input);
t_run	*run_add_rules(t_run *run, t_rules *rules);
t_run	*run_free(t_run **run);

#endif
