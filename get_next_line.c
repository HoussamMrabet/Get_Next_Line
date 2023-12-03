/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:13:43 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/29 16:00:40 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char **s)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(*s + i) && *(*s + i) != '\n')
		i++;
	if (*(*s + i) == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (free(*s), *s = NULL, NULL);
	while (j < i)
	{
		*(str + j) = *(*s + j);
		j++;
	}
	return (*(str + j) = '\0', tmp = ft_strdup(*s + i),
		free(*s), *s = tmp, str);
}

static int	ft_read(char **saves, int fd)
{
	char	*buffer;
	int		length;
	long	length;
	long	l;
	size_t	i;

	length = 0;
	l = 0;
	i = (size_t)BUFFER_SIZE;
	buffer = (char *)malloc(i + 1);
	if (!buffer)
		return (free(*saves), *saves = NULL, -1);
	while (i > INT_MAX)
	{
		length += read(fd, buffer, INT_MAX);
		if (length <= 0)
			return (free(buffer), length);
		i -= INT_MAX;
	}
	l = length;
	length = read(fd, buffer, BUFFER_SIZE);
	if (length <= 0)
		return (free(buffer), length);
	l += length;
	*(buffer + length) = '\0';
	*saves = ft_strjoin(*saves, buffer);
	free(buffer);
	if (!saves || !*saves)
		return (-1);
	return (length);
}

char	*get_next_line(int fd)
{
	static char	*saves = NULL;
	long			length;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(saves), saves = NULL, NULL);
	length = 1;
	while (ft_strchr(saves, '\n') == -1 && length > 0)
		length = ft_read(&saves, fd);
	if (length <= 0 && (!saves || !*saves))
		return (free(saves), saves = NULL, NULL);
	return (ft_get_line(&saves));
}
