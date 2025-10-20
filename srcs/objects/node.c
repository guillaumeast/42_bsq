#include "bsq.h"

t_node	*node_new(size_t cap)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->data = NULL;
	node->data = malloc(cap);
	if (!node->data)
		return (node_free(&node));
	node->len = 0;
	node->cap = cap;
	return (node);
}

t_node	*node_add_new(t_node **first, t_node *prev, size_t cap)
{
	t_node	*node;

	if (!prev)
		return (NULL);
	node = node_new(cap);
	if (!node)
		return (node_free(first));
	prev->next = node;
	return (node);
}

t_str	*node_to_str(t_node **node, size_t len)
{
	t_str 	*str;
	t_node	*tmp;
	size_t	i;
	size_t	j;

	str = str_new(NULL, len, len + 1);
	if (!str || !node || !*node)
		return (str_free(&str));
	str->str = malloc(len + 1);
	if (!str->str)
		return (str_free(&str));
	i = 0;
	tmp = *node;
	while (tmp)
	{
		j = 0;
		while (i <= len && j < tmp->len)
			str->str[i++] = tmp->data[j++];
		tmp = tmp->next;
	}
	if (i != len)
		return (str_free(&str));
	str->str[i] = '\0';
	node_free(node);
	return (str);
}

t_node	*node_free(t_node **node)
{
	if (!node || !*node)
		return (NULL);
	if ((*node)->data)
		free((*node)->data);
	if ((*node)->next)
		node_free(&((*node)->next));
	(*node)->data = NULL;
	(*node)->next = NULL;
	free(*node);
	*node = NULL;
	return (NULL);
}
