//
//  ft_putstr.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}
