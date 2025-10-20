#include "bsq.h"

static t_str	*read_fd(int fd, char *buffer, size_t cap);
static char		*grow_buffer(char *buffer, size_t content_len, size_t cap_need);

t_str	*read_file(const char *file_path)
{
	int		fd;
	char	*buffer;
	t_str	*res;

	fd = open(file_path, O_RDONLY);
	buffer = malloc(BUFFER_SIZE);
	if (fd == -1 || !buffer)
		return (NULL);
	res = read_fd(fd, buffer, BUFFER_SIZE);
	close(fd);
	return (res);
}

static t_str	*read_fd(int fd, char *buffer, size_t cap)
{
	size_t	len;
	ssize_t	bytes_read;
	ssize_t available;

	len = 0;
	available = BUFFER_SIZE - 1;
	while ((bytes_read = read(fd, buffer + len, available)) == available)
	{
		len += bytes_read;
		cap *= 2;
		buffer = grow_buffer(buffer, len, cap);
		if (!buffer)
			return (NULL);
		available = cap - len - 1;
	}
	if (bytes_read < 0)
		return (NULL);
	len += bytes_read;
	buffer[len] = '\0';
	return (str_new(buffer, len, cap));
}

static char	*grow_buffer(char *buffer, size_t content_len, size_t new_cap)
{
	char	*new_buffer;
	size_t	i;

	new_buffer = malloc(new_cap);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < content_len)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}
