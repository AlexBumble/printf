/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:42:42 by jbane             #+#    #+#             */
/*   Updated: 2020/11/14 11:42:49 by jbane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	else if (lst->next == NULL)
		return (lst);
	else
		return (ft_lstlast(lst->next));
}
