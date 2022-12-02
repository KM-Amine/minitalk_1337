/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:13:12 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/10 17:15:13 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count >= 18446744073709551615UL || size >= 18446744073709551615UL)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}
