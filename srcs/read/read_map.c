#include "bsq.h"

static void		read_more(t_run **run, int fd);
static void		set_width_and_read(t_run **r, int fd, size_t row_width);
static t_bool	buff_grow(t_buffer *buffer, size_t new_cap);

void	read_map(t_run **run, int fd)
{
	char	*start;
	char	*p;
	char	*end;

	// fprintf(stderr, "\n--------------------\n");
	// fprintf(stderr, "read_map()\n");
	// fprintf(stderr, "--------------------\n");
	if (!run || !*run)
		return ;
	start = (*run)->buffer.data + (*run)->rules.input.str_len;
	p = start;
	end = (*run)->buffer.data + (*run)->buffer.len;
	while (p < end && *p != '\n')
		p++;
	if (p < end)
		set_width_and_read(run, fd, (size_t)(p - start));
	else
		read_more(run, fd);
	// fprintf(stderr, "--------------------\n");
}

static void	read_more(t_run **r, int fd)
{
	char	*start;
	char	*p;
	char	*end;
	size_t	free;
	ssize_t	bytes_read;

	// fprintf(stderr, "┌- read_more()\n");
	if (!buff_grow(&((*r)->buffer), MAP_BUFF_SIZE))
		return (run_free(r));
	start = (*r)->buffer.data + (*r)->buffer.len;
	free = (*r)->buffer.cap - (*r)->buffer.len;
	while ((bytes_read = read(fd, start, free)) > 0)
	{
		p = start;
		end = start + bytes_read;
		(*r)->buffer.len += (size_t) bytes_read;
		// fprintf(stderr, "└-> bytes_read = %zd => buffer.len = %zu\n", bytes_read, (*r)->buffer.len);
		while (p < end && *p != '\n')
			p++;
		if (p < end)
			return (set_width_and_read(r, fd, (size_t)(p - (*r)->buffer.data) - (*r)->rules.input.str_len));
		free -= (size_t) bytes_read;
		if (free == 0 && !buff_grow(&((*r)->buffer), (*r)->buffer.cap << 1))
				return (run_free(r));
		start = (*r)->buffer.data + (*r)->buffer.len;
	}
	return (run_free(r));
}

static void	set_width_and_read(t_run **r, int fd, size_t row_width)
{
	size_t	file_len;
	ssize_t	bytes_read;
	char	*buffer;
	size_t	available;

	// fprintf(stderr, "\n┌- set_width_and_read(%zu)\n", row_width);
	(*r)->map.row_width = row_width;
	(*r)->map.row_len = row_width + 1;
	(*r)->map.str_len = ((*r)->rules.height * (*r)->map.row_len);
	file_len = (*r)->rules.input.str_len + (*r)->map.str_len;
	if (row_width == 0 || !buff_grow(&((*r)->buffer), file_len + 1))
		return (run_free(r));
	buffer = (*r)->buffer.data + (*r)->buffer.len;
	(*r)->map.p = (*r)->buffer.data + (*r)->rules.input.str_len;
	available = (*r)->buffer.cap - (*r)->buffer.len;
	while (available > 0 && (bytes_read = read(fd, buffer, available)) > 0)
	{
		(*r)->buffer.len += (size_t) bytes_read;
		// fprintf(stderr, "└-> bytes_read = %zd => buffer.len = %zu\n", bytes_read, (*r)->buffer.len);
		buffer += bytes_read;
		available -= bytes_read;
	}
	if (bytes_read == -1 || (*r)->buffer.len != file_len)
	{
		// fprintf(stderr, "└-> buffer.len = %zu | file_len = %zu\n", (*r)->buffer.len, file_len);
		return (run_free(r));
	}
	(*r)->dp.tab = malloc(row_width * sizeof *(*r)->dp.tab);
	if (!(*r)->dp.tab)
	{
		// fprintf(stderr, "└-> Failed dp allocation\n");
		return (run_free(r));
	}
}

static t_bool	buff_grow(t_buffer *buffer, size_t new_cap)
{
	char	*new_data;
	size_t	i;

	// fprintf(stderr, "├-> buff_grow(%zu -> %zu) => ", buffer->cap, new_cap);
	if (buffer->cap >= new_cap)
	{
		// fprintf(stderr, "No-op\n");
		return (TRUE);
	}
	new_data = malloc(new_cap);
	if (!new_data)
	{
		// fprintf(stderr, "Failed\n");
		return (FALSE);
	}
	i = 0;
	while (i < buffer->len)
	{
		new_data[i] = buffer->data[i];
		i++;
	}
	free(buffer->data);
	buffer->data = new_data;
	buffer->cap = new_cap;
	// fprintf(stderr, "Grown\n");
	return (TRUE);
}
