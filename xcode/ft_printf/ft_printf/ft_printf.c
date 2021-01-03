#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int	res;
	t_pfs	*r_node;

	res = 0;
	r_node = init_pfs(s);
	if (r_node)
	{
		va_start(r_node->args, s);
		if (s)
		{
			res = ft_parse(r_node);
			deinit_pfs(r_node);
		}
		va_end(r_node->args);
	}
	return (res);
}
