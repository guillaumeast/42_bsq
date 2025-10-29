#ifndef PARSE_H
# define PARSE_H

# include "bsq.h"

// TODO: delete unused maccros
# define RULES_CHARSET_LEN 3	// empty + obstacle + filler
# define RULES_MIN_WIDTH 4		// height + empty + obstacle + filler
# define RULES_MIN_LEN 5		// height + empty + obstacle + filler + '\n'
# define RULES_MAX_WIDTH 13		// INT_MAX (10 chars) + charset (3 chars)
# define RULES_MAX_LEN 14		// INT_MAX (10 chars) + charset (3 chars) + '\n' (1 char)

void	parse_rules(t_run **run);
void	parse_map(t_run **run);

#endif
