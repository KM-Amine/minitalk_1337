/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:29:55 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/10 07:58:23 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i + ft_strlen(little) <= len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, ft_strlen(little)) == 0)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
