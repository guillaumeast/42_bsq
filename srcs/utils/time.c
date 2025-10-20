#include "bsq.h"

static void	print_run_time(t_run_time *time);
static void	print_avg_time(t_exec_time *exec_time);
static inline long long ns_since(const struct timespec a, const struct timespec b);

void	print_exec_time(t_exec_time *exec_time)
{
	size_t		i;

	fprintf(stderr, "┌-----------------------------------┐\n");
	fprintf(stderr, "| C - v2.4.0                        |\n");
	fprintf(stderr, "├-----------------------------------┤\n");
	fprintf(stderr, "|  Read  |  Parse |  Write | Total  |\n");
	fprintf(stderr, "├-----------------------------------┤\n");
	i = 0;
	while (i < BENCH_ITERATIONS)
		print_run_time(&(exec_time->runs[i++]));
	fprintf(stderr, "├-----------------------------------┤\n");
	fprintf(stderr, "|  Average                          |\n");
	fprintf(stderr, "├-----------------------------------┤\n");
	print_avg_time(exec_time);
	fprintf(stderr, "└-----------------------------------┘\n");
}

static void	print_run_time(t_run_time *time)
{
	time->read = (int) (ns_since(time->read_start, time->parse_start) / 1e6);
	time->parse = (int) (ns_since(time->parse_start, time->write_start) / 1e6);
	time->write = (int) (ns_since(time->write_start, time->write_end) / 1e3);
	time->total = (int) (ns_since(time->read_start, time->end) / 1e6);
	fprintf(stderr, "| %3d ms | %3d ms | %3d µs | %3d ms |\n", \
		time->read, time->parse, time->write, time->total);
}

static void	print_avg_time(t_exec_time *exec_time)
{
	size_t	i;
	int		avg_read;
	int		avg_parse;
	int		avg_write;
	int		avg_total;

	avg_read = 0;
	avg_parse = 0;
	avg_write = 0;
	avg_total = 0;
	i = 0;
	while (i < BENCH_ITERATIONS)
	{
		avg_read += exec_time->runs[i].read;
		avg_parse += exec_time->runs[i].parse;
		avg_write += exec_time->runs[i].write;
		avg_total += exec_time->runs[i].total;
		i++;
	}
	avg_read /= i;
	avg_parse /= i;
	avg_write /= i;
	avg_total /= i;
	fprintf(stderr, "| %3d ms | %3d ms | %3d µs | %3d ms |\n", \
		avg_read, avg_parse, avg_write, avg_total);
}

static inline long long ns_since(const struct timespec a, const struct timespec b)
{
    return (b.tv_sec - a.tv_sec)*1000000000LL + (b.tv_nsec - a.tv_nsec);
}
