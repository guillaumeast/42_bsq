#include "bsq.h"

void	init_rules(t_rules *rules)
{
	init_str(&(rules->input));
	rules->height = 0;
	rules->emp = '\0';
	rules->obs = '\0';
	rules->fil = '\0';
}
