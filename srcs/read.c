#include "bsq.h"

static t_str	*read_fd(int fd, t_node **first_buffer, size_t cap);

t_str	*read_file(const char *file_path)
{
	int		fd;
	t_node	*first_buffer;
	t_str	*res;

	fd = open(file_path, O_RDONLY);
	first_buffer = node_new(BUFFER_SIZE);
	if (fd == -1 || !first_buffer)
		return (NULL);
	res = read_fd(fd, &first_buffer, BUFFER_SIZE);
	close(fd);
	return (res);
}

static t_str	*read_fd(int fd, t_node **first_buffer, size_t cap)
{
	size_t	sm_len;
	ssize_t	bytes_read;
	t_node	*current;

	current = *first_buffer;
	sm_len = 0;
	while ((bytes_read = read(fd, current->data, cap)) == (ssize_t) cap)
	{
		current->len += bytes_read;
		sm_len += bytes_read;
		cap *= 2;
		current = node_add_new(first_buffer, current, cap);
		if (!current)
			return (NULL);
	}
	if (bytes_read < 0)
	{
		node_free(first_buffer);
		return (NULL);
	}
	current->len += bytes_read;
	sm_len += bytes_read;
	return (node_to_str(first_buffer, sm_len));
}
