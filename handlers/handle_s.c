//
//  handle_s.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "../ft_printf.h"

int	handle_s(struct s_spfr *spfr)
{
	return ft_putstr((char *)spfr->arg);
}
