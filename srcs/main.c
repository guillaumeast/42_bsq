#include "bsq.h"

void	ft_putstr(char *str);
static inline long long ns_since(const struct timespec a, const struct timespec b);

int	main(int argc, char **argv)
{
	struct timespec start, start_read, end_read, end_parse, end_write;
	int		i;
	t_str	*input;
	t_run	run;

	clock_gettime(CLOCK_MONOTONIC, &start);
	if (argc == 1)
	{
		// TODO: read from stdin
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			clock_gettime(CLOCK_MONOTONIC, &start_read);
			input = read_file(argv[i]);
			clock_gettime(CLOCK_MONOTONIC, &end_read);
			if (!parse(&run, input))
			{
				write(2, "map error\n", 10);
				return (1);
			}
			clock_gettime(CLOCK_MONOTONIC, &end_parse);
			print_result(&run);
			clock_gettime(CLOCK_MONOTONIC, &end_write);
			printf("┌---------------------------------┐\n");
			printf("| C - v2.1.0 - %zuk x %zuk map      |\n", run.rules.width / 1000, run.rules.width / 1000);
			printf("├---------------------------------┤\n");
			printf("|  Read |  Parse | Write | Total  |\n");
			printf("├---------------------------------┤\n");
			printf("| %.0f ms | %.0f ms | %.0f ms | %.0f ms |\n", \
				ns_since(start_read, end_read) /1e6, \
				ns_since(end_read, end_parse) /1e6, \
				ns_since(end_parse, end_write) /1e6, \
				ns_since(start, end_write) /1e6);
			printf("└---------------------------------┘\n");
			if (i < argc - 1)
				write(1, "\n", 1);
			run_free(&run);
			i++;
		}
	}
	return (0);
}

static inline long long ns_since(const struct timespec a, const struct timespec b)
{
    return (b.tv_sec - a.tv_sec)*1000000000LL + (b.tv_nsec - a.tv_nsec);
}
