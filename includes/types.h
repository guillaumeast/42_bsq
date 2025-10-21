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
}	t_str;

typedef struct s_rules
{
	size_t	len;
	size_t	height;
	char	emp;
	char	obs;
	char	fil;
}	t_rules;

typedef struct	s_dp
{
	int		*dp1;
	int		*dp2;
}	t_dp;

typedef struct s_bsq
{
	int		size;
	size_t	row;
	size_t	col;
}	t_bsq;

typedef struct s_run
{
	t_rules	rules;
	size_t	width;
	size_t	row_len;
	t_str	*input;
	t_str	*map;
	t_dp	*dp;
	t_bsq	bsq;
}	t_run;

typedef struct	s_bounds
{
	size_t	rowmin;
	size_t	rowmax;
	size_t	colmin;
	size_t	colmax;
}	t_bounds;

#endif
