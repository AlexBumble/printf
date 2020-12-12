//
//  parse_flag.c
//  ft_printf
//
//  Created by Алексей Бузов on 12.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	parse_flag(t_pfs *n)
{
	int	i;
	int	bufN;

	i = 0;
	bufN = 0;
	while (ft_isFlag(n->str[i])) {
		if (ft_contains("0-", n->str[i]) && n->spfr->f->width == 0)
		{
			if(n->str[i] == '0')
				n->spfr->f->flags[0] = '0';
			else if (n->str[i] == '-')
				n->spfr->f->flags[1] = '-';
		}
		else if(((bufN = ft_atoi(n->str)) > 0 || n->str[i] == '*') && !n->spfr->f->accuracy)
		{
			if (n->str[i] == '*')
			{
				n->spfr->f->width = -1;
			}
			else
			{
				n->spfr->f->width = bufN;
				i += ft_numlen(bufN);
				continue;
			}
		}
		else if (n->str[i] == '.')
		{
			n->spfr->f->accuracy = 1;
		}
		else if (((bufN = ft_atoi(n->str)) > 0 || n->str[i] == '*') && n->spfr->f->accuracy)
		{
			if (n->str[i] == '*')
			{
				n->spfr->f->size = -1;
			}
			else
			{
				n->spfr->f->size = bufN;
				i += ft_numlen(bufN);
				continue;
			}
		}
		else if (ft_isType(*n->str))
			break;
		i++;
	}
	return (i);
}
