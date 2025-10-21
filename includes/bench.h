#ifndef BSQ_BENCH_H
# define BSQ_BENCH_H

# include "bsq.h"
# include <time.h>

# define BENCH_ITERATIONS 100

typedef struct s_run_time
{
	struct timespec	read_start;
	struct timespec parse_start;
	struct timespec write_start;
	struct timespec end;
	long long		read;
	long long		parse;
	long long		write;
	long long		total;
}	t_run_time;

typedef struct s_exec_time
{
	struct timespec	start;
	t_run_time 		runs[BENCH_ITERATIONS];
	long long		avg_read;
	long long		avg_parse;
	long long		avg_write;
	long long		avg_total;
	struct timespec	end;
}	t_exec_time;

void	print_exec_time(t_exec_time *exec_time);

#endif
