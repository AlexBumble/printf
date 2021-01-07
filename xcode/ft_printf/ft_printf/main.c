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
	int n = -100;

//	int i = ft_printf("Hello world%s\nHello world%05s\nHello world%-5%\nHello world%-5c\n", s,s,c);
//	printf("<!>res >>> %d\n", i);
//	int ij= printf("Hello world%s\nHello world%05s\nHello world%-5%\nHello world%-5c\n", s,s,c);
//	printf("<!>res >>> %d\n", ij);

	int i = ft_printf("Hello world%05d\n", n);
	printf("<!>res >>> %d\n", i);
	int ij= printf("Hello world%05u\n", n);
	printf("<!>res >>> %d\n", ij);
	return (0);
}
