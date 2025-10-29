#include "bsq.h"

void	read_file(t_run **run, const char *file_path)
{
	int	fd;

	if (!run || !*run || !file_path)
		return (run_free(run));
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (run_free(run));
	read_rules(run, fd);
	parse_rules(run);
	read_map(run, fd);
	close(fd);
}
