#ifndef CHUNK_H
# define CHUNK_H

# include "bsq.h"

t_chunk_arr	*chunk_new_arr();
t_chunk		*chunk_new(t_chunk_arr **chunk_arr);
t_str		*chunk_to_str(t_chunk_arr **chunk_arr);
t_chunk		*chunk_free_all(t_chunk_arr **tab);

#endif
