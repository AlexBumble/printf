//
//  ft_strlen.c
//  ft_printf
//
//  Created by Joramun Bane on 12/7/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
