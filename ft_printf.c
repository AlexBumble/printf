#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_list	*r_node;
	int	i;

	r_node = malloc(sizeof(t_list));
	i = 0;
	if (r_node)
	{
		while(str[i])
		{
				printf("%d\n", i);
				i++;
		}
		r_node->content = (char *)str;
	}
	printf("%s\n", r_node->content);
	return (0);
}
