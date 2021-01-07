//
//  handle_di.c
//  ft_printf
//
//  Created by Алексей Бузов on 05.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"


int	handle_di(struct s_spfr *spfr)
{
	int		res;
	int		num_abs;
	int		num_length;
	char	*num_str;
	
	res = 0;
	num_abs = (int)spfr->arg;
	num_length = 0;
	if (num_abs < 0)
	{
		res += ft_putchar('-');
		num_abs = num_abs * -1;
		num_length += 1;
	}
	num_str = ft_itoa(num_abs);
	num_length += (int)ft_strlen(num_str);
	if (spfr->f->flags[0] && !spfr->f->flags[1])
		res += apply_flag(spfr, num_length);
	res += ft_putstr(num_str);
	if (spfr->f->flags[1])
		res += apply_flag(spfr, num_length);
	return (res);
}
