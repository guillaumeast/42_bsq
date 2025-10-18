#include "bsq.h"

void	ft_putstr(char *str);
static inline long long ns_since(const struct timespec a, const struct timespec b);

int	main(int argc, char **argv)
{
	struct timespec start, start_read, end_read, start_write, end_write, end;
	int		i;
	t_str	*input;

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
			if (!input)
				return (1); // TODO: print error
			clock_gettime(CLOCK_MONOTONIC, &start_write);
			write(1, input->content, input->len);
			clock_gettime(CLOCK_MONOTONIC, &end_write);
			printf("read:  %.3f ms\n", ns_since(start_read, end_read)  / 1e6);
			printf("write: %.3f ms\n", ns_since(start_write, end_write) / 1e6);
			free(input);
			i++;
		}
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("total: %.3f ms\n", ns_since(start, end) / 1e6);
	return (0);
}

static inline long long ns_since(const struct timespec a, const struct timespec b)
{
    return (b.tv_sec - a.tv_sec)*1000000000LL + (b.tv_nsec - a.tv_nsec);
}
