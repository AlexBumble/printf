/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:41:14 by jbane             #+#    #+#             */
/*   Updated: 2020/11/14 11:41:16 by jbane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_lst;

	while (*lst && del)
	{
		next_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_lst;
	}
}
