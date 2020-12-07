#ifndef PRINTF_H

# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_spfr
{
	int				(*handler)(struct s_spfr *);
	void			*arg;
}					t_spfr;

typedef	struct		s_pfs
{
	char			*str;
	int				r_count;
	va_list			args;
	t_spfr			*spfr;
}					t_pfs;

int					ft_printf(const char *str, ...);
int					ft_parse(t_pfs *node);
int					ft_putstr(char *str);
int					ft_putchar(char c);
size_t				ft_strlen(const char *s);

/* Handlers */
int					handle_s(struct s_spfr *spfr);

#endif
