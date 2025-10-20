#include "bsq.h"

static void	exec_from_files(int argc, char **argv);
static void	exec_bench(char *file_path);

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "stdin reading not yet implemented\n", 34);	// TODO
	else if (argc == 3 && strcmp(argv[1], "--bench") == 0)
		exec_bench(argv[2]);
	else
		exec_from_files(argc, argv);
	return (0);
}

static void	exec_bench(char *file_path)
{
	t_exec_time	exec_time;
	t_str	*input;
	t_run	run;
	size_t	i;

	fprintf(stderr, "Benchmarking on %d iterations...\n", BENCH_ITERATIONS);
	clock_gettime(CLOCK_MONOTONIC, &(exec_time.start));
	i = 0;
	while (i < BENCH_ITERATIONS)
	{
		clock_gettime(CLOCK_MONOTONIC, &(exec_time.runs[i].read_start));
		input = read_file(file_path);
		clock_gettime(CLOCK_MONOTONIC, &(exec_time.runs[i].parse_start));
		if (!parse(&run, input))
			write(2, "map error\n", 10);
		else
		{
			clock_gettime(CLOCK_MONOTONIC, &(exec_time.runs[i].write_start));
			print_result(&run);
			clock_gettime(CLOCK_MONOTONIC, &(exec_time.runs[i].write_end));
		}
		run_free(&run);
		clock_gettime(CLOCK_MONOTONIC, &(exec_time.runs[i++].end));
	}
	print_exec_time(&exec_time);
}

static void	exec_from_files(int argc, char **argv)
{
	int		i;
	t_str	*input;
	t_run	run;

	i = 1;
	while (i < argc)
	{
		input = read_file(argv[i]);
		if (!parse(&run, input))
			write(2, "map error\n", 10);
		else
			print_result(&run);
		if (i < argc - 1)
			write(1, "\n", 1);
		run_free(&run);
		i++;
	}
}
