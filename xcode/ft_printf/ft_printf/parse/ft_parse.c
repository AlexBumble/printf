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
	node->spfr->arg = va_arg(node->args, void*);
	return (1);
}

static	int	parse_spfr(t_pfs *node)
{
	int	i;
	int	typeIsFind;

	i = 1;
	typeIsFind = 0;
	while (!typeIsFind && *++node->str)
	{
		if (ft_isFlag(*node->str))
			i += parse_flag(node);
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
