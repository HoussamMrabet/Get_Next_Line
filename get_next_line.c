/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:13:43 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/20 18:02:39 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char **s, int *len)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < *len && *(*s + i) != '\n')
		i++;
	if (i < *len)
		if (*(*s + i) == '\n')
			i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (free(*s), *s = NULL, *len = 0, NULL);
	while (j < i)
	{
		*(str + j) = *(*s + j);
		j++;
	}
	*(str + j) = '\0';
	return (tmp = ft_strdup(*s + i, *len - i),
		free(*s), *s = tmp, *len = *len - i, str);
}

static int	ft_read(char **saves, int fd, int *len)
{
	char	*buffer;
	int		length;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*saves), *saves = NULL, -1);
	length = read(fd, buffer, BUFFER_SIZE);
	if (length <= 0)
		return (free(buffer), length);
	buffer[length] = '\0';
	*saves = ft_strjoin(*saves, *len, buffer, length);
	free(buffer);
	if (!saves)
		return (-1);
	return (length);
}

char	*get_next_line(int fd)
{
	static char	*saves = NULL;
	static int	saves_len = 0;
	int			length;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, NULL, 0) < 0)
		return (free(saves), saves = NULL, NULL);
	length = 1;
	while (ft_strchr(saves, &saves_len, '\n') == -1 && length > 0)
	{
		length = ft_read(&saves, fd, &saves_len);
		if (length > 0)
			saves_len += length;
	}
	if (length <= 0 && (!saves || saves_len == 0))
		return (free(saves), saves = NULL, saves_len = 0, NULL);
	return (ft_get_line(&saves, &saves_len));
}
