/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:15:40 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/22 14:28:48 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s1) + 1;
	duplicate = (char *)ft_calloc(len, sizeof(char));
	if (!duplicate)
		return (0);
	ft_strlcpy(duplicate, s1, len);
	return (duplicate);
}
