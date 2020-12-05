/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:43:30 by jbane             #+#    #+#             */
/*   Updated: 2020/11/14 11:43:31 by jbane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_list	*ft_lstaddcontent(t_list *lst, void *content)
{
	if (lst)
	{
		lst->next = ft_lstnew(content);
		lst = lst->next;
	}
	else
		lst = ft_lstnew(content);
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r_lst;
	t_list	*i_lst;
	void	*content;

	i_lst = NULL;
	r_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		i_lst = ft_lstaddcontent(i_lst, content);
		if (!i_lst)
		{
			del(content);
			i_lst = ft_lstlast(r_lst);
		}
		r_lst = r_lst == NULL ? i_lst : r_lst;
		lst = lst->next;
	}
	return (r_lst);
}
