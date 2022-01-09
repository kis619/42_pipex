/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:36:49 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/28 20:36:49 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*new_elem;

	if (!f || !lst)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	new_elem = begin;
	while (lst->next)
	{
		lst = lst->next;
		new_elem->next = ft_lstnew(f(lst->content));
		if (new_elem->next == NULL)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		new_elem = new_elem->next;
	}
	return (begin);
}
