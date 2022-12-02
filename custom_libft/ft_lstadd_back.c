/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:24:27 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/10 07:53:51 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*tmp;

	if (!lst || !n)
		return ;
	if (!*lst)
	{
		*lst = n;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = n;
}
