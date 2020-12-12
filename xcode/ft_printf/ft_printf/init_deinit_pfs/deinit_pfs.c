//
//  deinit_pfs.c
//  ft_printf
//
//  Created by Алексей Бузов on 12.12.2020.
//  Copyright © 2020 Joramun Bane. All rights reserved.
//

#include "ft_printf.h"

void	deinit_pfs(t_pfs *node)
{
	free(node->spfr->f);
	free(node->spfr);
	free(node);
}
