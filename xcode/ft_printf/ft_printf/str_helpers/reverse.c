//
//  reverse.c
//  ft_printf
//
//  Created by Алексей Бузов on 05.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include <stdio.h>

void	reverse(char *str, int start_i, int end_i)
{
	char	c;

	while (start_i < end_i)
	{
		c = str[start_i];
		str[start_i] = str[end_i];
		str[end_i] = c;
		start_i++;
		end_i--;
	}
}
