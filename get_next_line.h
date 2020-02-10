/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:26:53 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/10 16:04:46 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAILURE	-1

int				get_next_line(int fd, char **line);
int				ft_strlen(char *s, char c);
char			*ft_substr(char *s, int start, int len);
int				ft_strchr(char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
void			ft_strcpy(char *dst, char *src);
char			*ft_strmove(char *s);
int				ft_verif(char *tmp, int ret);
void			*ft_calloc(size_t count, size_t size);

#endif
