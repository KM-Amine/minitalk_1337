/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:03:42 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/02 12:03:57 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_2(char	*s1, char	*s2)
{
	int		len;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen((s2));
	result = (char *)ft_calloc(sizeof(char), len + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (result);
}

char	*ft_read_line(char *tmp, int fd)
{
	int		is_read;
	char	*buff;

	is_read = 1;
	buff = (char *)ft_calloc(sizeof(char), BUFFER_SIZE +1);
	if (buff == NULL)
		return (0);
	while (is_read != 0 && ft_strchr(tmp, '\n') == 0)
	{
		is_read = read(fd, buff, BUFFER_SIZE);
		if (is_read == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		tmp = ft_strjoin_2(tmp, buff);
		if (tmp == NULL)
		{
			free(buff);
			return (NULL);
		}
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	return (free(buff), tmp);
}

char	*ft_turncate_line(char *tmp, char **line)
{
	int		i;
	char	*remain;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	*line = ft_substr(tmp, 0, i + 1);
	if (*line == NULL)
	{
		*line = NULL;
		return (NULL);
	}
	remain = ft_substr(tmp, i + 1, ft_strlen(tmp));
	if (remain == NULL)
	{
		free(*line);
		*line = NULL;
		return (tmp);
	}
	free(tmp);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	if (tmp == NULL)
		tmp = (char *)ft_calloc(sizeof(char), 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_read_line(tmp, fd);
	if (tmp == NULL)
		return (NULL);
	if (tmp[0] == 0)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp = ft_turncate_line(tmp, &line);
	if (tmp == NULL || line == NULL)
		return (NULL);
	return (line);
}
