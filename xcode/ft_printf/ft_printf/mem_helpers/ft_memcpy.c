//
//  ft_memcpy.c
//  ft_printf
//
//  Created by Алексей Бузов on 05.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*dst_ucp;
	unsigned char	*src_ucp;

	i = -1;
	dst_ucp = (unsigned char *)dst;
	src_ucp = (unsigned char *)src;
	if (dst_ucp || src_ucp)
		while (++i < (int)n)
			dst_ucp[i] = src_ucp[i];
	return (dst);
}
