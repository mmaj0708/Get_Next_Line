/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:26:53 by mmaj              #+#    #+#             */
/*   Updated: 2020/01/24 17:45:49 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);
int				ft_strlen(char *s, char c);
char			*ft_line(char *s1);
int				ft_strchr(char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
void			ft_strcpy(char *dst, char *src);
char			*ft_strmove(char *s);
int				ft_verif(char *tmp);
void			ft_verif2(int ret, char *tmp);

#endif
