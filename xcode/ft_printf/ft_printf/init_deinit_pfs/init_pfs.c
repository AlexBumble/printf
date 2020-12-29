//
//  init_pfs.c
//  ft_printf
//
//  Created by Алексей Бузов on 12.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

static	t_flag	*ft_newFlag()
{
	t_flag	*new;
	
	new = malloc(sizeof(t_flag));
	if (new)
	{
		new->flags[0] = '\0';
		new->flags[1] = '\0';
		new->accuracy = 0;
		new->size = 0;
		new->width = 0;
	}
	return (new);
}

t_pfs			*init_pfs(const char *s)
{
	t_pfs	*node;

	node = malloc(sizeof(t_pfs));
	if (node)
	{
		node->str = (char *)s;
		node->r_count = 0;
		node->spfr = malloc(sizeof(t_spfr));
		if (node->spfr)
		{
			node->spfr->f = ft_newFlag();
			if (node->spfr->f)
				return (node);
			else
			{
				free(node->spfr);
				free(node);
			}
		}
		else
			free(node);
	}
	return (NULL);
}
