#include "bsq.h"

static char	check_rules(char *str, int len);

t_run	*get_rules(t_run *run, char *str)
{
	int		line_len;
	char	*height_str;

	line_len = 0;
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	run->rules.size.height = ft_atoi_n(str, line_len - RULES_CHARSET_LEN);
	if (!check_rules(str, line_len) || run->rules.size.height == 0)
		return (clean_run(run));
	run->rules.empty = str[line_len - RULES_CHARSET_LEN];
	run->rules.obstacle = str[line_len - (RULES_CHARSET_LEN - 1)];
	run->rules.filled = str[line_len - (RULES_CHARSET_LEN - 2)];
	return (run);
}

static char	check_rules(char *str, int linelen)
{
	int	i;
	int	j;

	if (linelen < RULES_MIN_LEN)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		if (i >= linelen - RULES_CHARSET_LEN)
		{
			j = 1;
			while (str[i + j])
			{
				if (str[i] == str[i + j++])
					return (0);
			}
		}
		i++;
	}
	return (1);
}
