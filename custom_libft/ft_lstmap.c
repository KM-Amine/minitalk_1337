/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:20:22 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/10 07:55:10 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dup;
	t_list	*node;

	if (!lst || !f || !del)
		return (0);
	dup = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst -> content));
		if (node == NULL)
		{
			ft_lstclear(&dup, del);
			return (0);
		}
		ft_lstadd_back(&dup, node);
		lst = lst -> next;
	}
	return (dup);
}
