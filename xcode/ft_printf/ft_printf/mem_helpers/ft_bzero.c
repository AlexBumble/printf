//
//  ft_bzero.c
//  ft_printf
//
//  Created by Алексей Бузов on 05.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*s_ucp;

	i = -1;
	s_ucp = (unsigned char *)s;
	while (++i < (int)n)
		s_ucp[i] = '\0';
}
