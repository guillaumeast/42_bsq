#include "bsq.h"

// Checks if a character is printable (ASCII range 32–126)
t_bool	is_print(char c)
{
	c = (unsigned char) c;
	if (c < 32 || c > 126)
		return (FALSE);
	return (TRUE);
}

// Converts the first n characters of a string to an integer, returns -1 if invalid
int	ft_fast_atoi_n(char *str, size_t n)
{
	char	*end;
	int		result = 0;

	end = str + n;
	while (str < end)
	{
		if ((unsigned char) (*str - '0') < 10)
			result = result * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return (result);
}
