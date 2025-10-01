/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouieb <adouieb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:31:04 by adouieb           #+#    #+#             */
/*   Updated: 2025/09/30 14:49:03 by adouieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_run	from_file_to_run(t_filepath path)
{
	t_read_content	content;

	printf("||===> %s\n", path);
	content.content = NULL;
	content.fd = 0;
	content.size = 0;
	content.byte_count = 0;
	ft_read_file(path, &content);
	return (init_run(content.content));
}

t_run	*from_files_to_runs(t_filepath *paths, int size)
{
	return (file_to_run_map(paths, size, from_file_to_run));
}

t_run	from_stdin_to_run(t_filepath path)
{
	t_read_content	content;

	content.content = NULL;
	content.fd = 0;
	content.size = 0;
	content.byte_count = 0;
	ft_read_stdin(path, &content);
	return (init_run(content.content));
}

t_run	*from_stdin_to_runs(void)
{
	char	*_;

	_ = "";
	return (file_to_run_map(&_, 1, from_stdin_to_run));
}

// valgrind --leak-check=full --track-origins=yes ./a.out tests/invalid/charset_atoi_all_minus tests/invalid/charset_atoi_all_plus tests/invalid/charset_atoi_break tests/invalid/charset_atoi_minus tests/invalid/charset_atoi_plus tests/invalid/charset_atoi_spaces tests/invalid/charset_dup tests/invalid/charset_miss tests/invalid/charset_non_printable tests/invalid/diff_len_empty tests/invalid/diff_len_min tests/invalid/diff_len_plus tests/invalid/map_charset_out tests/invalid/map_charset_wrong tests/invalid/map_empty tests/invalid/map_empty_lines tests/invalid/map_empty_lines_w_rules tests/invalid/map_empty_w_rules tests/invalid/map_no_new_line tests/invalid/wrong_len_max tests/invalid/wrong_len_min

int	main(int argc, char **argv)
{
	t_run	*runs;
	int		size;

	if (argc == 1)
	{
		size = 1;
		runs = from_stdin_to_runs();
	}
	else
	{
		size = argc - 1;
		runs = from_files_to_runs(argv + 1, size);
	}
	run_to_run_map(runs, size, parse);
	run_to_run_map(runs, size, init_solution_table);
	run_to_run_map(runs, size, resolve);
	run_to_run_map(runs, size, print_result);
	run_to_run_map(runs, size, clean_run);
	free(runs);
	runs = NULL;
	return (0);
}
