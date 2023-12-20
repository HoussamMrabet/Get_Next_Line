/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:09:45 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/20 10:20:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

int		ft_strchr(char *s, int *len, char c);
char	*ft_strdup(char *s, int len);
char	*ft_strjoin(char *s1, int len, char *s2, int length);
char	*get_next_line(int fd);

#endif
