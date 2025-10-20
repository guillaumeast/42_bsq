#include "bsq.h"

static t_chunk_arr	*grow_arr(t_chunk_arr **arr);

t_chunk_arr	*chunk_new_arr()
{
	t_chunk_arr *arr;

	arr = malloc(sizeof(t_chunk_arr));
	if (!arr)
		return (NULL);
	arr->cap = 8;
	arr->tab = malloc(arr->cap * sizeof(t_chunk *));
	if (!arr->tab)
	{
		free(arr);
		return (NULL);
	}
	arr->count = 0;
	arr->len = 0;
	return (arr);
}

t_chunk	*chunk_new(t_chunk_arr **tab)
{
	t_chunk	*chunk;
	size_t	count;
	size_t	cap;

	count = (*tab)->count;
	*tab = grow_arr(tab);
	if (!*tab)
		return (NULL);
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	(*tab)->tab[count] = chunk;
	if (count != 0)
		cap = (*tab)->tab[count - 1]->cap * 2;
	else
		cap = BUFFER_SIZE;
	count++;
	chunk->data = NULL;
	chunk->data = malloc(cap);
	if (!chunk->data)
		return (chunk_free_all(tab));
	chunk->cap = cap;
	chunk->len = 0;
	(*tab)->count = count;
	return (chunk);
}

t_str	*chunk_to_str(t_chunk_arr **tab)
{
	t_str	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!tab || !*tab)
		return (NULL);
	str = str_new(NULL, (*tab)->len, (*tab)->len + 1);
	if (!str)
		return (NULL);
	str->str = malloc((*tab)->len + 1);
	if (!str->str)
	{
		free(str);
		chunk_free_all(tab);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (j < (*tab)->count)
	{
		k = 0;
		while (k < (*tab)->tab[j]->len)
			str->str[i++] = (*tab)->tab[j]->data[k++];
		j++;
	}
	str->str[i] = '\0';
	chunk_free_all(tab);
	return (str);
}

static t_chunk_arr	*grow_arr(t_chunk_arr **arr)
{
	t_chunk **new_tab;
	size_t	i;

	if ((*arr)->cap > (*arr)->count)
		return (*arr);
	(*arr)->cap = (*arr)->cap * 2;
	new_tab = malloc((*arr)->cap * sizeof(t_chunk *));
	if (!new_tab)
	{
		chunk_free_all(arr);
		return (NULL);
	}
	i = 0;
	while (i < (*arr)->count)
	{
		new_tab[i] = (*arr)->tab[i];
		i++;
	}
	free((*arr)->tab);
	(*arr)->tab = new_tab;
	return (*arr);
}

t_chunk	*chunk_free_all(t_chunk_arr **tab)
{
	size_t	i;

	if (!tab || !*tab)
		return (NULL);
	i = 0;
	while (i < (*tab)->count)
	{
		free((*tab)->tab[i]->data);
		free((*tab)->tab[i]);
		i++;
	}
	free((*tab)->tab);
	free(*tab);
	*tab = NULL;
	return (NULL);
}
