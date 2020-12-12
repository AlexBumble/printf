//
//  ft_putchar.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (c == 's')
		printf("s");
	return (write(1, &c, 1));
}
