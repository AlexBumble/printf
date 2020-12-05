#ifndef PRINTF_H

# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "lst/lst.h"

int	ft_printf(const char *str, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
