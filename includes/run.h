#ifndef RUN_H
# define RUN_H

# include "bsq.h"

t_run	*run_new();
void	run_add_rules(t_run **run);
void	run_free(t_run **run);

#endif
