#ifndef TYPES_H
# define TYPES_H

typedef char	t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_buffer
{
	char	*data;
	size_t	len;
	size_t	cap;
}	t_buffer;

typedef struct s_str
{
	char	*p;
	size_t	row_width;
	size_t	row_len;
	size_t	str_len;
}	t_str;

typedef struct s_rules
{
	t_str	input;
	size_t	height;
	char	emp;
	char	obs;
	char	fil;
}	t_rules;

typedef struct	s_dp
{
	int		prev;
	int		*tab;
}	t_dp;

typedef struct s_bsq
{
	int		size;
	size_t	row;
	size_t	col;
}	t_bsq;

typedef struct s_run
{
	t_buffer	buffer;
	t_rules		rules;
	t_str		map;
	t_dp		dp;
	t_bsq		bsq;
}	t_run;

typedef struct	s_bounds
{
	size_t	rowmin;
	size_t	rowmax;
	size_t	colmin;
	size_t	colmax;
}	t_bounds;

#endif
