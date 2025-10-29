#ifndef READ_H
# define READ_H

# include "bsq.h"

// Initial buffer for map input = 16 ko
# define MAP_BUFF_SIZE 16000

void	read_file(t_run **run, const char *file_path);
void	read_rules(t_run **run, int fd);
void	read_map(t_run **run, int fd);

#endif