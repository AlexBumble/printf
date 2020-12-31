//
//  handle_s.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	handle_s(struct s_spfr *spfr)
{
	int res;
	
	res = 0;
	if (spfr->f->flags[0] && !spfr->f->flags[1])
		res += apply_flag(spfr, (int)ft_strlen((char *)spfr->arg));
	res += ft_putstr((char *)spfr->arg);
	if (spfr->f->flags[1])
		res += apply_flag(spfr, (int)ft_strlen((char *)spfr->arg));
	return (res);
}
