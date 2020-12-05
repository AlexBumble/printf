#include "ft_printf.h"

void ft_parse(t_list *node, char *str)
{
	node->content = str;
}

void ft_print_node(void *node)
{
	t_list	*r_node;
	r_node = (t_list *)node;
	printf("%s\n", r_node->content);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	char *str;
	va_list		args;
	t_list	*r_node;
	t_list	*i_node;

	str = (char *)s;
	r_node = malloc(sizeof(t_list));
	i_node = r_node;
	if (r_node)
	{
		i = 0;
		va_start(args, s);
		while(str[i])
		{
				if(str[i] == '%' && str[i+1] && str[i+1] == 's')
				{
					i_node->content = malloc(i + 1);
					if (i_node->content)
					{
						ft_strlcpy(i_node->content, str, i - 1);
						str = str + i + 1;
						i = 0;
					}
					i_node->next = ft_lstnew(NULL);
					i_node = i_node->next;
					ft_parse(i_node, va_arg(args, char *));
				}
				i++;
		}
		i_node->next = ft_lstnew(NULL);
		i_node = i_node->next;
		i_node->content = (char *)str;
	}
	ft_lstiter(r_node, &ft_print_node);
	va_end(args);
	return (0);
}
