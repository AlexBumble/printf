//
//  parse_flag.c
//  ft_printf
//
//  Created by Алексей Бузов on 12.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	void	parse_flag_zero_or_minus(t_pfs *n, int i)
{
	if(n->str[i] == '0')
		n->spfr->f->flags[0] = '0';
	else if (n->str[i] == '-')
		n->spfr->f->flags[1] = '-';
}

static	void	parse_flag_star_or_num(t_pfs *n, int i, int num, int f)
{
	if (n->str[i] == '*' && f)
		n->spfr->f->width = -1;
	else if (n->str[i] == '*' && !f)
		n->spfr->f->size = -1;
	else if (f)
		n->spfr->f->width = num;
	else
		n->spfr->f->size = num;
}

int	parse_flag(t_pfs *n)
{
	int	i;
	int	bufN;

	i = 0;
	bufN = 0;
	while (ft_isFlag(n->str[i])) {
		if (ft_contains("0-", n->str[i]) && n->spfr->f->width == 0)
			parse_flag_zero_or_minus(n, i);
		else if((bufN = ft_atoi(n->str + i)) > 0 || n->str[i] == '*')
		{
			parse_flag_star_or_num(n, i, bufN, !n->spfr->f->accuracy);
			if (bufN)
			{
				i += ft_numlen(bufN);
				continue;

			}
		}
		else if (n->str[i] == '.')
			n->spfr->f->accuracy = 1;
		else if (ft_isType(*n->str))
			break;
		i++;
	}
	return (i);
}
