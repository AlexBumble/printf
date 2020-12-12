//
//  main.c
//  ft_printf
//
//  Created by Joramun Bane on 12/5/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	main() {
	char *s = "123";

	int i = ft_printf("Hello world%0s", s);
	printf("res >>> %d\n", i);
	int ij= printf("Hello world%05s", s);
	printf("res >>> %d\n", ij);
	return (0);
}
