#include "bsq.h"

// TODO: 25 lines max
// TODO: create struct to store variables
void	print_result(t_run *run)
{
	size_t	i;
	size_t	map_len;
	size_t	line_len;
	size_t	rowmin;
	size_t	rowmax;
	size_t	colmin;
	size_t	colmax;
	size_t	row;
	size_t	col;
	t_str	*res;

	line_len = run->rules.width + 1;
	map_len = run->map->len;
	res = str_new(map_len + 1);
	rowmin = run->bsq.index / line_len - (run->bsq.size - 1);
	rowmax = run->bsq.index / line_len;
	colmin = run->bsq.index % line_len - (run->bsq.size - 1);
	colmax = run->bsq.index % line_len;
	i = 0;
	while (i < map_len)
	{
		row = i / line_len;
		col = i % line_len;
		if (run->map->str[i] == '\n')
		{
			res->str[i] = '\n';
			i++;
			continue;
		}
		if (row >= rowmin && row <= rowmax && col >= colmin && col <= colmax)
			res->str[i] = run->rules.fil;
		else
			res->str[i] = run->map->str[i];
		i++;
	}
	res->str[i] = '\0';
	res->len = map_len;
	write(1, res->str, res->len);
}
