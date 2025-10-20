#ifndef NODE_H
# define NODE_H

# include "bsq.h"

t_node	*node_new(size_t cap);
t_node	*node_add_new(t_node **first, t_node *prev, size_t cap);
t_str	*node_to_str(t_node **node, size_t len);
t_node	*node_free(t_node **node);

#endif
