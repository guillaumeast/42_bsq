#include "bsq.h"

static t_str	*read_fd(int fd, t_chunk_arr **buffers);

t_str	*read_file(const char *file_path)
{
	int			fd;
	t_chunk_arr	*buffers;
	t_str		*res;

	fd = open(file_path, O_RDONLY);
	buffers = chunk_new_arr();
	if (fd == -1 || !buffers)
		return (NULL);
	res = read_fd(fd, &buffers);
	close(fd);
	return (res);
}

static t_str	*read_fd(int fd, t_chunk_arr **buffers)
{
	ssize_t	bytes_read;
	t_chunk	*current;

	current = chunk_new(buffers);
	if (!current)
		return (NULL);
	while ((bytes_read = read(fd, current->data, current->cap)) == (ssize_t) current->cap)
	{
		fprintf(stderr, "Hey\n");
		current->len += bytes_read;
		(*buffers)->len += bytes_read;
		current = chunk_new(buffers);
		if (!current)
			return (NULL);
		fprintf(stderr, "New_cap = %zu\n", current->cap);
	}
	if (bytes_read < 0)
	{
		chunk_free_all(buffers);
		return (NULL);
	}
	current->len += bytes_read;
	(*buffers)->len += bytes_read;
	return (chunk_to_str(buffers));
}
