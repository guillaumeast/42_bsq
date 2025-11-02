#include "bsq.h"

static void	exec_bench(char *file_path);
static void	exec_from_files(int argc, char **argv);
static void	exec_from_stdin();

// Entry point: runs benchmark mode or solves maps from given files
int	main(int argc, char **argv)
{
	if (argc == 1)
		exec_from_stdin();
	else if (argc == 3 && strcmp(argv[1], "--bench") == 0)
		exec_bench(argv[2]);
	else
		exec_from_files(argc, argv);
	return (0);
}

// Runs multiple iterations on a map file to benchmark execution time
static void	exec_bench(char *file_path)
{
	t_exec_time	exec_time;
	t_run	*run;
	char	*input;
	size_t	i;

	fprintf(stderr, "Benchmarking on %d iterations...\n", BENCH_ITERATIONS);
	clock_gettime(CLOCK_BENCH, &(exec_time.start));
	i = 0;
	while (i < BENCH_ITERATIONS)
	{
		clock_gettime(CLOCK_BENCH, &(exec_time.runs[i].read_start));
		run = run_new();
		read_file(&run, file_path);
		clock_gettime(CLOCK_BENCH, &(exec_time.runs[i].parse_start));
		if (run)
			input = (*run).input->str;
		parse_rules(&run, input, (*run).input->len, &((*run).rules));
		parse_map(&run);
		clock_gettime(CLOCK_BENCH, &(exec_time.runs[i].write_start));
		if (run)
		{
			print_result(run);
			run_free(&run);
		}
		else
			write(2, "map error\n", 10);
		clock_gettime(CLOCK_BENCH, &(exec_time.runs[i++].end));
	}
	print_exec_time(&exec_time);
}

// Processes and solves each map file provided as a command-line argument
static void	exec_from_files(int argc, char **argv)
{
	t_run	*run;
	char	*input;
	int		i;

	i = 1;
	while (i < argc)
	{
		run = run_new();
		read_file(&run, argv[i]);
		if (run)
			input = (*run).input->str;
		parse_rules(&run, input, (*run).input->len, &((*run).rules));
		parse_map(&run);
		if (run)
		{
			print_result(run);
			run_free(&run);
		}
		else
			write(2, "map error\n", 10);
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
}

// Processes and solves the map provided via stdin
static void	exec_from_stdin()
{
	t_run	*run;
	char	*input;

	run = run_new();
	input = NULL;
	read_file(&run, NULL);
	if (run)
		input = (*run).input->str;
	parse_rules(&run, input, (*run).input->len, &((*run).rules));
	parse_map(&run);
	if (run)
	{
		print_result(run);
		run_free(&run);
	}
	else
		write(2, "map error\n", 10);
}
