#include "bsq.h"

int	ft_strs_len(char **strs, int size, char *sep)
{
	int	i;
	int	len;
	int	sep_len;

	i = 0;
	len = 0;
	sep_len = ft_strlen(sep);
	while (strs[i])
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += sep_len;
		i++;
	}
	return (len);
}

char	*ft_strjoin(char **strs, int size, char *sep)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strs_len(strs, size, sep) + 1));
	if (!res)
		return (NULL);
	res[0] = '\0';
	i = 0;
	while (strs[i])
	{
		ft_strncat(res, strs[i], ft_strlen(strs[i]));
		if (i < size - 1)
			ft_strncat(res, sep, ft_strlen(sep));
		i++;
	}
	return (res);
}
