//
//  handle_c.c
//  ft_printf
//
//  Created by Алексей Бузов on 03.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	handle_c(struct s_spfr *spfr)
{
	int res;
	
	res = 0;
	if (spfr->f->flags[0] && !spfr->f->flags[1])
		res += apply_flag(spfr, 1);
	res += ft_putchar((char)spfr->arg);
	if (spfr->f->flags[1])
		res += apply_flag(spfr, 1);
	return (res);
}
