//
//  ft_parse.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	int	parse_type(t_pfs *node)
{
	if (*node->str == 's')
		node->spfr->handler = &handle_s;
	else if (*node->str == '%')
		node->spfr->handler = &handle_prsnt;
	else if (*node->str == 'c')
		node->spfr->handler = &handle_c;
	else if (*node->str == 'p')
		node->spfr->handler = &handle_p;
	else if (*node->str == 'd' || *node->str == 'i')
		node->spfr->handler = &handle_di;
	node->spfr->arg = va_arg(node->args, void*);
	return (1);
}

static	int	parse_spfr(t_pfs *node)
{
	int	i;
	int buf;
	int	typeIsFind;

	i = 1;
	buf = 0;
	typeIsFind = 0;
	while (!typeIsFind && *++node->str)
	{
		if (ft_isFlag(*node->str))
		{
			buf = parse_flag(node);
			i += buf;
			node->str += buf - 1;
		}
		else if (ft_isType(*node->str))
		{
			i += parse_type(node);
			typeIsFind = 1;
		}
		else
			i++;
	}
	return (i);
}

int	ft_parse(t_pfs *node)
{
	while (*node->str)
	{
		if (*node->str != '%')
		{
			node->str = node->str + ft_putchar(*node->str);
			node->r_count++;
		}
		else
		{
			node->str = node->str + parse_spfr(node);
			if (node->spfr->handler)
				node->r_count += node->spfr->handler(node->spfr);
		}
	}
	return (node->r_count);
}
