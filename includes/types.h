#ifndef TYPES_H
# define TYPES_H

typedef	char*	t_filepath;
typedef char*	t_file_content;
typedef char**  t_board;

typedef struct rules
{
	int		width;
	int		heigth;
	char	empty;
	char	obstacle;
	char	filled;
}	t_rules;

typedef enum e_status
{
	VALID,
	ERROR,
}	t_status;

typedef	struct cell
{
	int	x;
	int	y;
	int	value;
}	t_cell;

typedef	struct solution
{
	t_board	table;
	t_cell	last_best;
}	t_solution;

typedef struct run
{
	t_file_content	content;
	t_rules			rules;
	t_board			map;
	t_solution		solution;
	t_status		status;
}	t_run;

#endif