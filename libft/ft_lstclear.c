/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:19:10 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/28 20:19:10 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_element;

	if (!del)
		return ;
	if (lst)
	{
		while (lst && *lst)
		{
			next_element = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_element;
		}
	}
	*lst = NULL;
}
