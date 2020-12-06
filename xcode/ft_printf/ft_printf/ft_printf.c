#include "ft_printf.h"

int	ft_parse(t_pfl *node)
{
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int	res;
	t_pfl	*r_node;
	
	res = 0;
	r_node = malloc(sizeof(r_node));
	if (r_node && s)
	{
		r_node->str = (char *)s;
		r_node->r_count = res;
		va_start(r_node->args, s);
		res = ft_parse(r_node);
		va_end(r_node->args);
		free(r_node);
	}
	return (res);
}
