//
//  apply_flag.c
//  ft_printf
//
//  Created by Алексей Бузов on 31.12.2020.
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

int	apply_flag(struct s_spfr *spfr, int argLen)
{
	int length;
	char selected_flag;
	int res;
	
	res = 0;
	length = argLen;
	if (length < spfr->f->width || spfr->f->width  == -1)
	{
		length = spfr->f->width  == -1 ? -1 : spfr->f->width - length;
		selected_flag = select_flag(spfr->f->flags);
		while (length != 0)
		{
			length -= ft_putchar(selected_flag);
			res++;
		}
	}
	return (res);
}
