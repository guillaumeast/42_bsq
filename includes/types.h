#ifndef TYPES_H
# define TYPES_H

# define BUFFER_SIZE 1000000
# define RULES_MIN_LEN 4
# define RULES_CHARSET_LEN 3

typedef char	t_bool;
# define FALSE = 0
# define TRUE = 1

typedef struct size
{
	int	width;
	int	height;
}	t_size;

typedef struct rules
{
	t_size	size;
	char	empty;
	char	obstacle;
	char	filled;
}	t_rules;

#endif
