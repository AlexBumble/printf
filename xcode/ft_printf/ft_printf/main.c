//
//  main.c
//  ft_printf
//
//  Created by Joramun Bane on 12/5/20.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

int	main() {
	char *p = "pp";
	char *s = "123";
	char c = '1';

	int i = ft_printf("Hello world%-4s", c);
	printf("<!>res >>> %d\n", i);
	int ij= printf("Hello world%-4s", c);
	printf("<!>res >>> %d\n", ij);
	return (0);
}
