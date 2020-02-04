/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:26:07 by mmaj              #+#    #+#             */
/*   Updated: 2020/02/04 19:04:19 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
	res[j] = '\0';
	free(s);
	s = NULL;
	return (res);
}

int		ft_verif(char *save, int ret)
{
	if (ret == FAILURE)
		return (FAILURE);
	if (ft_strchr(save, '\n') >= 0)
		return (1);
	return (SUCCESS);
}


int		get_next_line(int fd, char **line)
{
	static char		*save;
	char			*buff;
	int				ret;

	if (line == NULL
		|| BUFFER_SIZE < 1
		|| fd < 0
		|| (!save && (!(save = malloc(1))
 		|| (*save = 0))) 
		|| !(buff = malloc(BUFFER_SIZE + 1)))
		return (FAILURE);
	
	while (ft_strchr(save, '\n') == FAILURE
		&& (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(save = ft_strjoin(save, buff)))
			return (-1);
	}
	free(buff);
	buff = NULL;
	ret = ft_verif(save, ret);
	*line = ft_substr(save, 0, ft_strchr(save, '\n'));
	save = ft_strmove(save);
	return (ret);
}

// int		get_next_line(int fd, char **line)
// {
// 	static	char	*tmp;
// 	char			*buff;
// 	char			*temp;
// 	int				ret;

// 	ret = SUCCESS;
// 	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0 || (!tmp && (!(tmp = malloc(1))
// 		|| (*tmp = 0))) || !(buff = malloc(BUFFER_SIZE + 1)))
// 		return (FAILURE);
// 	while (ft_strchr(tmp, '\n') < 0 && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
// 	{
// 		buff[ret] = 0;
// 		if (!(tmp = ft_strjoin(tmp, buff)))
// 			return (FAILURE);
// 	}
// 	free(buff);
// 	buff = NULL;
// 	if (ret == FAILURE)
// 		return (FAILURE);
// 	*line = ft_substr(tmp, 0, ft_strchr(tmp, '\n'));
// 	temp = tmp;
// 	ret = ft_verif(tmp);
// 	tmp = ft_substr(tmp, ft_strchr(tmp, '\n') + 1, ft_strchr(tmp, '\0'));
// 	free(temp);
// 	temp = NULL;
// 	return (ret);
// }