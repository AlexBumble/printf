#ifndef PRINTF_H

# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct        s_list
{
    char            *content;
    struct s_list    *next;
}                    t_list;

typedef	struct	s_pfl
{
	char	*str;
	int	r_count;
	va_list	*args;
}			t_pfl;

t_list                *ft_lstnew(void *content);
void                ft_lstadd_front(t_list **lst, t_list *new);
int                    ft_lstsize(t_list *lst);
t_list                *ft_lstlast(t_list *lst);
void                ft_lstadd_back(t_list **lst, t_list *new);
void                ft_lstdelone(t_list *lst, void (*del)(void *));
void                ft_lstclear(t_list **lst, void (*del)(void *));
void    ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list                *ft_lstmap(t_list *lst, void *(*f)(void *),
                                                void (*del)(void *));

int	ft_printf(const char *str, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
