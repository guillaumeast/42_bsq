#ifndef RUN_H
# define RUN_H

# include "bsq.h"

t_run	init_run(t_file_content content);
t_run	*clean_run(t_run *run_addr);

t_run	*init_map(t_run *run_addr);
t_run	*clean_map(t_run *run_addr);

t_run	*init_file_content(t_run *run_addr);
t_run	*clean_file_content(t_run *run_addr);

t_run	*init_cell(t_run *run_addr);
t_run	*clean_cell(t_run *run_addr);
t_run	*init_solution(t_run *run_addr);
t_run	*clean_solution(t_run *run_addr);
t_run	*init_solution_table(t_run *run_addr);

t_run   *init_size(t_run *run_addr);
t_run   *clean_size(t_run *run_addr);
t_run   *init_rules(t_run *run_addr);
t_run   *clean_rules(t_run *run_addr);

#endif