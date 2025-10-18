#include "bsq.h"

t_str	*read_file(const char *file_path)
{
	int			fd;
	char		buffer[BUFFER_SIZE];
	t_str		*res;
	ssize_t		read_len;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	res = str_new(BUFFER_SIZE);
	while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		str_append_buf(&res, buffer, read_len);
		if (!res)
		{
			close(fd);
			return (str_free(&res));
		}
	}
	close(fd);
	if (read_len == -1)
		return (str_free(&res));
	return (res);
}
