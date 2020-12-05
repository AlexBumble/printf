#include "ft_printf.h"

void ft_parse(t_list *node, char *str)
{
	node->content = str;
}

void ft_print_node(t_list *node)
{
	printf("%s", node->content);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	char *str;
	va_list		args;
	t_list	*r_node;
    t_list  *b_node;

	str = (char *)s;
	r_node = ft_lstnew(NULL);
    b_node = ft_lstnew(NULL);
	if (r_node)
	{
		i = 0;
		va_start(args, s);
		while(str[i])
		{
				if(str[i] == '%' && str[i+1] && str[i+1] == 's')
				{
					r_node->content = malloc(i + 1);
					if (r_node->content)
					{
						ft_strlcpy(r_node->content, str, i - 1);
						str = str + i + 1;
						i = 0;
					}
					ft_parse(b_node, va_arg(args, char *));
                    ft_lstadd_back(&r_node, b_node);
                    b_node = ft_lstnew(NULL);
				}
				i++;
		}
		b_node->content = (char *)str;
        ft_lstadd_back(&r_node, b_node);
	}
	ft_lstiter(r_node, &ft_print_node);
	va_end(args);
	return (0);
}
