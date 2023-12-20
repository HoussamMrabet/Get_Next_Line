/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:14:27 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/20 18:01:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, int *len, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (i < *len)
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strcpy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (free(str), NULL);
	return (ft_strcpy(str, s, len), str);
}

char	*ft_strjoin(char *s1, int len, char *s2, int length)
{
	char	*str;

	if (!s1)
		return (ft_strdup(s2, length));
	str = (char *)malloc(len + length);
	if (!str)
		return (free(s1), NULL);
	return (ft_strcpy(str, s1, len), ft_strcpy(str + len, s2, length),
		free(s1), str);
}
