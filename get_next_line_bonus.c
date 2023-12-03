/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:32:26 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/29 16:04:41 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*find_fd_node(t_list **head, int fd)
{
	t_list	*new_node;
	t_list	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->buffer = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

static void	ft_del_node(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*lst = tmp->next;
			free(tmp->buffer);
			tmp->buffer = NULL;
			free(tmp);
			tmp = NULL;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

static char	*ft_get_line(t_list **head, t_list *node, int fd)
{
	char	*str;
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (*(node->buffer + i) && *(node->buffer + i) != '\n')
		i++;
	if (*(node->buffer + i) == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (ft_del_node(head, fd), NULL);
	while (j < i)
	{
		*(str + j) = *(node->buffer + j);
		j++;
	}
	*(str + j) = '\0';
	tmp = ft_strdup(node->buffer + i);
	if (!tmp)
		return (free(str), str = NULL, ft_del_node(head, fd), NULL);
	return (free(node->buffer), node->buffer = tmp, str);
}

static int	ft_read(t_list *node)
{
	char	*buffer;
	int		length;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(node->buffer), node->buffer = NULL, -1);
	length = read(node->fd, buffer, BUFFER_SIZE);
	if (length <= 0)
		return (free(buffer), buffer = NULL, length);
	*(buffer + length) = '\0';
	node->buffer = ft_strjoin(node->buffer, buffer);
	free(buffer);
	buffer = NULL;
	if (!node->buffer)
		return (-1);
	return (length);
}

char	*get_next_line(int fd)
{
	static t_list	*lbuff = NULL;
	t_list			*current;
	int				length;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	current = find_fd_node(&lbuff, fd);
	if (!current)
		return (NULL);
	length = 1;
	while (ft_strchr(current->buffer, '\n') == -1 && length > 0)
		length = ft_read(current);
	if (length < 0 || (length == 0 && (!current->buffer
				|| !*(current->buffer))))
		return (ft_del_node(&lbuff, fd), NULL);
	return (ft_get_line(&lbuff, current, fd));
}
