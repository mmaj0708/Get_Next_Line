/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:26:07 by mmaj              #+#    #+#             */
/*   Updated: 2020/01/27 16:04:16 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_strmove(char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s, '\n');
	if (!(res = malloc((ft_strlen(s, 0) - i) + 1)))
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	while (s[i])
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = 0;
	free(s);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!s)
		return ;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
}

int		ft_verif(char *tmp)
{
	if (ft_strchr(tmp, '\n'))
		return (1);
	return (0);
}

void	ft_verif2(int ret, char *tmp)
{
	if (ret == 0)
	{
		ft_bzero(tmp, ft_strlen(tmp, 0));
		tmp = 0;
		free(tmp);
	}
	return ;
}

int		get_next_line(int fd, char **line)
{
	static	char	*tmp;
	char			*buff;
	int				ret;

	if (!line || BUFFER_SIZE <= 0 || fd <= 0 || (*line = 0)
		|| !(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strchr(tmp, '\n') && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = 0;
		tmp = ft_strjoin(tmp, buff);
	}
	if (ret == -1)
		return (-1);
	*line = ft_line(tmp);
	ret = ft_verif(tmp);
	tmp = ft_strmove(tmp);
	ft_verif2(ret, tmp);
	free(buff);
	return (ret);
}
