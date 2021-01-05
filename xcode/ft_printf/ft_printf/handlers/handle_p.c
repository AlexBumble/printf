//
//  handle_p.c
//  ft_printf
//
//  Created by Алексей Бузов on 03.01.2021.
//  Copyright © 2021 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	void	reverse(char *str, int start_i, int end_i)
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

static	void	dec_to_hex(char *str, long int l)
{
	int	i;
	int	ost;

	i = 0;
	while (l > 0)
	{
		ost = l % 16;
		if (ost > 9)
			str[i] = 'a' + ost - 10;
		else
			str[i] = '0' + ost;
		l = l / 16;
		++i;
	}
}

static	void		make_address(char *address, char *result)
{
	long int	address_long;

	ft_memcpy(&address_long, &address, sizeof(void *));
	dec_to_hex(result, address_long);
	reverse(result, 0, (int)ft_strlen(result) - 1);
}

int	handle_p(struct s_spfr *spfr)
{
	int		res;
	void	*address;
	char	p_address_str[18];
	int		p_address_length;
	
	res = 0;
	address = (char *)spfr->arg;
	ft_bzero(p_address_str, 18);
	make_address(address, p_address_str);
	p_address_length = address ? (int)ft_strlen(p_address_str) + 2 : 3;
	res += ft_putstr("0x");
	if (spfr->f->flags[0] && !spfr->f->flags[1])
		res += apply_flag(spfr, p_address_length);
	res += address ? ft_putstr(p_address_str) : ft_putchar('0');
	if (spfr->f->flags[1])
		res += apply_flag(spfr, p_address_length);
	return (res);
}
