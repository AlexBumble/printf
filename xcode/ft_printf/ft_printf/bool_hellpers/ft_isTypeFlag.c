//
//  ft_isType.c
//  ft_printf
//
//  Created by Joramun Bane on 12/9/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

int	ft_isType(char c)
{
	int		i;
	char	*typeFlags;

	i = 0;
	typeFlags = "s";
	while (typeFlags)
	{
		if (typeFlags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
