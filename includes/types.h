#ifndef TYPES_H
# define TYPES_H

# define BUFFER_SIZE 1000000
# define RULES_MIN_LEN 4
# define RULES_CHARSET_LEN 3

typedef char	t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_str
{
	char	*str;
	size_t	len;
	size_t	cap;
}	t_str;

typedef struct s_rules
{
	size_t	len;
	size_t	height;
	size_t	width;
	char	emp;
	char	obs;
	char	fil;
}	t_rules;

typedef struct s_bsq
{
	size_t	size;
	size_t	index;
}	t_bsq;

typedef struct	s_bounds
{
	size_t	rowmin;
	size_t	rowmax;
	size_t	colmin;
	size_t	colmax;
}	t_bounds;

typedef struct s_run
{
	t_str	*input;
	t_rules	rules;
	t_str	*map;
	size_t	line_count;
	int		*dp;
	t_bsq	bsq;
}	t_run;

#endif
