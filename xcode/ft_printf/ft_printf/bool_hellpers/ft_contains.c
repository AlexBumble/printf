//
//  ft_contains.c
//  ft_printf
//
//  Created by Алексей Бузов on 12.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

int	ft_contains(const char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
