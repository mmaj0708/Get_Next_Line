/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:26:34 by mmaj              #+#    #+#             */
/*   Updated: 2020/01/27 15:22:15 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s, char c)
{
	int	i;

	i = 0;
	if ((!s) || (!s[i]))
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;

	i = ft_strlen(s1, 0);
	if ((!s1) && (!s2))
		return (NULL);
	if (!(new = malloc(sizeof(new)
		* (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1))))
		return (NULL);
	if (s1)
		ft_strcpy(new, s1);
	ft_strcpy(&new[i], s2);
	free(s1);
	return (new);
}

int		ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_line(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(ft_strlen(s1, '\n') + 1)))
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
