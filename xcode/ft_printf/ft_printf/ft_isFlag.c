//
//  ft_isFlag.c
//  ft_printf
//
//  Created by Joramun Bane on 12/9/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

int	ft_isFlag(char c)
{
	int		i;
	char	*typeFlags;

	i = 0;
	typeFlags = "0-*.";
	while (typeFlags)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
