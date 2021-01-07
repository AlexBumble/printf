#ifndef PRINTF_H

# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** Cтруктура флага спецификатора.
** flags - поддерживаемые флаги:
**** 0 - '0';
**** 1 - '-';
** width - ширина идет до '.';
** accuracy - точность идет после '.';
** size - длинна идет после точности;
*/
typedef	struct		s_flag
{
	char			flags[2];
	int				width;
	int				accuracy;
	int				size;
}					t_flag;

/*
** Cтруктура спецификатора  %
** handler - функция для обработки текущего флага;
** arg - обезличиный аргемент флага;
** t_flag - структура флага;
*/
typedef	struct		s_spfr
{
	int				(*handler)(struct s_spfr *);
	void			*arg;
	t_flag			*f;
}					t_spfr;

/*
** Основная структура функциию.
** str - входящая строка ft_printf;
** r_count - счетчик результата ft_printf;
** args - аргументы va_list;
** t_spfr - структура спецификатора  %;
*/
typedef	struct		s_pfs
{
	char			*str;
	int				r_count;
	va_list			args;
	t_spfr			*spfr;
}					t_pfs;

int					ft_printf(const char *str, ...);

/*
** Init/deinit основной структуры.
*/
t_pfs				*init_pfs(const char *s);
void				deinit_pfs(t_pfs *node);

/*
** Парсер строки и печать результата,
** returns - кол-во напечатанных символов.
*/
int					ft_parse(t_pfs *node);
int					parse_flag(t_pfs *n);

/*
** Строковые хелперы..
*/
int					ft_putstr(char *str);
int					ft_putchar(char c);
void				reverse(char *str, int start_i, int end_i);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);

/*
** Числовые хелперы.
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_numlen(int n);

/*
** Булевы хелперы.
*/
int					ft_isType(char c);
int					ft_isFlag(char c);
int					ft_contains(const char *str, char c);

/*
** Хелперы работы с памятью.
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
** Обработчики спецификаторов.
*/
int					handle_s(struct s_spfr *spfr);
int					handle_prsnt(struct s_spfr *spfr);
int					handle_c(struct s_spfr *spfr);
int					handle_p(struct s_spfr *spfr);
int					handle_di(struct s_spfr *spfr);

/*
** Обработчики флага спецификатора.
*/
int			apply_flag(struct s_spfr *spfr, int argLen);

#endif
