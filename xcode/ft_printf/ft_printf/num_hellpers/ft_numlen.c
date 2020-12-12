//
//  ft_numlen.c
//  ft_printf
//
//  Created by Алексей Бузов on 12.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

int	ft_numlen(int n)
{
	if (n > 0)
	{
		return (1 + ft_numlen(n / 10));
	}
	return (0);
}
