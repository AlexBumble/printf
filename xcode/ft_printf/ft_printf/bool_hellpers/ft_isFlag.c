//
//  ft_isFlag.c
//  ft_printf
//
//  Created by Joramun Bane on 12/9/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	ft_isFlag(char c)
{
	int		i;
	char	str[1];
	char	*typeFlags;

	i = 0;
	str[0] = c;
	typeFlags = "0-*.";
	while (typeFlags[i])
	{
		if (typeFlags[i] == c)
			return (1);
		i++;
	}
	if (ft_atoi(str))
		return  (1);
	return (0);
}
