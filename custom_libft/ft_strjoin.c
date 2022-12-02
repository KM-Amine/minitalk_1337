/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:19:29 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/02 13:10:48 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1);
	len += ft_strlen((s2));
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}
*/

// if one of s1 or s2 is NULL strjoint works like strdup
char	*ft_strjoin(char	*s1, char	*s2)
{
	int		len;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen((s2));
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (result);
}
