//
//  ft_itoa.c
//  ft_printf
//
//  Created by Алексей Бузов on 06.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	long int	ft_numpow(long int n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_numpow(n, pow - 1));
}

static	void		ft_wrightlnum(long int n, char *buf, size_t blen)
{
	long int	pow;

	while (blen - 1 > 0)
	{
		pow = ft_numpow(10, blen - 2);
		*buf++ = n / pow + '0';
		n = n - n / pow * pow;
		blen--;
	}
	*buf = '\0';
}

static	void		ft_wrightnum(int n, char *buf, size_t blen)
{
	if (n < 0)
	{
		*buf++ = '-';
		ft_wrightlnum((long int)n * -1, buf++, blen - 1);
	}
	else
		ft_wrightlnum(n, buf, blen);
}

static	size_t		ft_numrank(int n, long int div)
{
	if (n > 0)
		return (ft_numrank(n * -1, div));
	if (n / div * -1 > 0)
		return (1 + ft_numrank(n, div * 10));
	return (1);
}

char				*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	len = (n >= 0 ? ft_numrank(n, 10) : ft_numrank(n, 10) + 1) + 1;
	res = malloc(len);
	if (res != NULL)
	{
		ft_wrightnum(n, res, len);
	}
	return (res);
}
