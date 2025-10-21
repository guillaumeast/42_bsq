#ifndef TYPES_H
# define TYPES_H

# define BUFFER_SIZE 1000000
# define RULES_MIN_LEN 4
# define RULES_CHARSET_LEN 3

typedef char	t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_rules
{
	size_t	len;
	size_t	height;
	size_t	width;
	char	emp;
	char	obs;
	char	fil;
}	t_rules;

typedef struct	s_bounds
{
	size_t	rowmin;
	size_t	rowmax;
	size_t	colmin;
	size_t	colmax;
}	t_bounds;

typedef struct s_run
{
	t_rules	rules;
	char	*input;
	size_t	row_len;
	size_t	input_len;
	char	*map;
	size_t	map_len;
	int		*dp;
	size_t	bsq_index;
	size_t	bsq_size;
}	t_run;

#endif
