/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:26:34 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/10 16:24:39 by mmaj             ###   ########.fr       */
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
	s1 = NULL;
	return (new);
}

int		ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (FAILURE);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s, '\0') - 1)
		return (new = ft_calloc(1, 1));
	if (!(new = (char *)ft_calloc(
		len <= (ft_strlen(s, '\0') - start) ? (len + 1) :
		ft_strlen(s, '\0') - start + 1, 1)))
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
