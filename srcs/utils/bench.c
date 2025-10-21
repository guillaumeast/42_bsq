#include "bsq.h"

static void		print_run_time(t_run_time *time);
static void		print_avg_time(t_exec_time *exec_time);
static void		compute_avg(t_exec_time *exec_time);
static void		print_time(long long ns);
static size_t	get_digits_count(const long long number);
static long long ns_since(const struct timespec a, const struct timespec b);

void	print_exec_time(t_exec_time *exec_time)
{
	size_t		i;

	fprintf(stderr, "┌-----------------------------------┐\n");
	fprintf(stderr, "| C - v2.5.0                        |\n");
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
	time->read = ns_since(time->read_start, time->parse_start);
	time->parse = ns_since(time->parse_start, time->write_start);
	time->write = ns_since(time->write_start, time->end);
	time->total = ns_since(time->read_start, time->end);
	fprintf(stderr, "|");
	print_time(time->read);
	fprintf(stderr, "|");
	print_time(time->parse);
	fprintf(stderr, "|");
	print_time(time->write);
	fprintf(stderr, "|");
	print_time(time->total);
	fprintf(stderr, "|\n");
}

static void	print_avg_time(t_exec_time *exec_time)
{
	compute_avg(exec_time);
	fprintf(stderr, "|");
	print_time(exec_time->avg_read);
	fprintf(stderr, "|");
	print_time(exec_time->avg_parse);
	fprintf(stderr, "|");
	print_time(exec_time->avg_write);
	fprintf(stderr, "|");
	print_time(exec_time->avg_total);
	fprintf(stderr, "|\n");
}

static void	compute_avg(t_exec_time *exec_time)
{
	size_t	i;

	exec_time->avg_read = 0;
	exec_time->avg_parse = 0;
	exec_time->avg_write = 0;
	exec_time->avg_total = 0;
	i = 0;
	while (i < BENCH_ITERATIONS)
	{
		exec_time->avg_read += exec_time->runs[i].read;
		exec_time->avg_parse += exec_time->runs[i].parse;
		exec_time->avg_write += exec_time->runs[i].write;
		exec_time->avg_total += exec_time->runs[i].total;
		i++;
	}
	exec_time->avg_read /= i;
	exec_time->avg_parse /= i;
	exec_time->avg_write /= i;
	exec_time->avg_total /= i;
}

static void	print_time(long long ns)
{
	size_t	dig_count;

	dig_count = get_digits_count(ns);
	if (ns <= 0)
		fprintf(stderr, "   0 ns ");
	else if (dig_count <= 3)
		fprintf(stderr, " %3d ns ", (int) ns);
	else if (dig_count <= 6)
		fprintf(stderr, " %3d µs ", (int) (ns / 1e3));
	else if (dig_count <= 9)
		fprintf(stderr, " %3d ms ", (int) (ns / 1e6));
	else if (dig_count <= 11)
		fprintf(stderr, " %3d  s ", (int) (ns / 1e9));
	else
		fprintf(stderr, " >99  s ");
}

static size_t	get_digits_count(const long long number)
{
	size_t		count;
	long long	nb;

	nb = number;
	count = 1;
	while ((nb = nb / 10) != 0)
		count++;
	return (count);
}

static long long ns_since(const struct timespec a, const struct timespec b)
{
    return (b.tv_sec - a.tv_sec)*1000000000LL + (b.tv_nsec - a.tv_nsec);
}
