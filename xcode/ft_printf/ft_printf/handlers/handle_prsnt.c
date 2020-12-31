//
//  handle_prsnt.c
//  ft_printf
//
//  Created by Алексей Бузов on 29.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	handle_prsnt(struct s_spfr *spfr)
{
	int res;
	
	res = 0;
	if (spfr->f->flags[0] && !spfr->f->flags[1])
		res += apply_flag(spfr, 1);
	res += ft_putchar('%');
	if (spfr->f->flags[1])
		res += apply_flag(spfr, 1);
	return (res);
}

