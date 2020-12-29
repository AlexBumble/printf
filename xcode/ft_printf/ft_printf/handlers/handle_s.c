//
//  handle_s.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	char	select_flag(char *flags)
{
	char res;
	
	res = flags[1] ? ' ' : '0';
	flags[0] = '\0';
	flags[1] = '\0';
	return (res);
}

static	int	apply_flag(struct s_spfr *spfr)
{
	int length;
	char selected_flag;
	int res;
	
	res = 0;
	length = (int)ft_strlen((char *)spfr->arg);
	if (length < spfr->f->width)
	{
		length = spfr->f->width - length;
		selected_flag = select_flag(spfr->f->flags);
		while (length != 0)
		{
			length -= ft_putchar(selected_flag);
			res++;
		}
	}
	return (res);
}

int	handle_s(struct s_spfr *spfr)
{
	int res;
	
	res = 0;
	if (spfr->f->flags[0] && !spfr->f->flags[1])
		res += apply_flag(spfr);
	res += ft_putstr((char *)spfr->arg);
	if (spfr->f->flags[1])
		res += apply_flag(spfr);
	return (res);
}
