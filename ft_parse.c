//
//  ft_parse.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	int	handle_s(t_spfr *spfr)
{
	return ft_putstr((char *)spfr->arg);
}

static	int	parse_type(t_pfs *node)
{
	if (*node->str == 's')
	{
		node->spfr->handler = &handle_s;
	}
	node->spfr->arg = va_arg(node->args, void*);
	return (1);
}

static	int	parse_spfr(t_pfs *node)
{
	int	i;

	i = 1;
	if (*++node->str != '%')
	{
		i += parse_type(node);
	}
	return (i);
}

int	ft_parse(t_pfs *node)
{
	while (*node->str)
	{
		if (*node->str != '%')
		{
			node->str = node->str +ft_putchar(*node->str);
			node->r_count++;
		}
		else
		{
			node->str = node->str + parse_spfr(node);
			node->r_count += node->spfr->handler(node->spfr);
		}
	}
	return (node->r_count);
}
