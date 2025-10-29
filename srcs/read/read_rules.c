#include "bsq.h"

static t_bool	set_buffer(t_run **run, size_t cap);

void	read_rules(t_run **run, int fd)
{
	char	*start;
	char	*p;
	size_t	free;
	ssize_t	bytes_read;
	char	*end;

	// fprintf(stderr, "\n--------------------\n");
	// fprintf(stderr, "read_rules()\n");
	// fprintf(stderr, "--------------------\n");
	// fprintf(stderr, "┌- set_buffer(%d) => ", RULES_MAX_LEN + 1);
	if (!set_buffer(run, RULES_MAX_LEN + 1))
		return (run_free(run));
	start = (*run)->buffer.data;
	p = start;
	free = (*run)->buffer.cap;
	while (free > 0 && (bytes_read = read(fd, p, free)) > 0)
	{
		p += (size_t) bytes_read;
		free -= (size_t) bytes_read;
		// fprintf(stderr, "└-> bytes_read = %zd => buffer.len = %zu\n", bytes_read, (size_t)(p - start));
	}
	if (bytes_read == -1)
		return (run_free(run));
	(*run)->buffer.len = (size_t)(p - start);
	p = start;
	end = start + (*run)->buffer.len;
	while (p < end && *p != '\n')
		p++;
	set_str(&((*run)->rules.input), start, (p - start), (p - start) + 1);
	// fprintf(stderr, "--------------------\n");
}

static t_bool	set_buffer(t_run **run, size_t cap)
{
	(*run)->buffer.data = malloc(cap);
	if (!(*run)->buffer.data)
	{
		// fprintf(stderr, "Failed\n");
		return (FALSE);
	}
	(*run)->buffer.cap = cap;
	(*run)->buffer.len = 0;
	// fprintf(stderr, "Done\n");
	return (TRUE);
}
