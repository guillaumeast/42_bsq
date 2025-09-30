#ifndef TYPES_H
# define TYPES_H

typedef	char*	t_filepath;
typedef char*	t_file_content;

typedef char**  t_board_c;
typedef char*	t_board_c_row;
typedef	char	t_board_c_cell;
typedef int**	t_board_i;
typedef int*	t_board_i_row;
typedef int		t_board_i_cell;

typedef struct boundary_box
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}	t_boundary_box;

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
	t_board_i	table;
	t_cell		last_best;
}	t_solution;

typedef struct run
{
	t_file_content	content;
	t_rules			rules;
	t_board_c		map;
	t_solution		solution;
	t_status		status;
}	t_run;

#endif
