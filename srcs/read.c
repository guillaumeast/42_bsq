#include "bsq.h"

static void	read_fd(t_run **run, int fd, char **buffer, size_t cap);
static void	grow_buffer(char **buffer, size_t content_len, size_t cap_need);

// Opens the given file, reads its content, and stores it in `run->input`
void	read_file(t_run **run, const char *file_path)
{
	int		fd;
	char	*buffer;


	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (run_free(run));
	if (file_path)
	{
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
			return (run_free(run));
		read_fd(run, fd, &buffer, BUFFER_SIZE);
		close(fd);
	}
	else
		read_fd(run, 0, &buffer, BUFFER_SIZE);
}

// Reads data from a file descriptor into a dynamically growing buffer
static void	read_fd(t_run **run, int fd, char **buffer, size_t cap)
{
	size_t	len;
	ssize_t	bytes_read;
	ssize_t available;

	len = 0;
	available = BUFFER_SIZE - 1;
	while ((bytes_read = read(fd, *buffer + len, available)) == available)
	{
		len += bytes_read;
		cap *= 2;
		grow_buffer(buffer, len, cap);
		if (!*buffer)
			return (run_free(run));
		available = cap - len - 1;
	}
	if (bytes_read < 0)
		return (run_free(run));
	len += bytes_read;
	(*buffer)[len] = '\0';
	(*run)->input = str_new(*buffer, len);
	if (!(*run)->input)
		return (run_free(run));
}

// Expands the buffer capacity while preserving its current content
static void	grow_buffer(char **buffer, size_t content_len, size_t new_cap)
{
	char	*new_buffer;
	size_t	i;

	new_buffer = malloc(new_cap);
	if (!new_buffer)
		return (free(*buffer));
	i = 0;
	while (i < content_len)
	{
		new_buffer[i] = (*buffer)[i];
		i++;
	}
	free(*buffer);
	*buffer = new_buffer;
}
