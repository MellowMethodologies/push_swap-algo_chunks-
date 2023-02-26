/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:20:54 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 17:29:13 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*next(char	*res)
{
	size_t	i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	if (i >= ft_strlen(res))
		return (free(res), NULL);
	s = malloc((ft_strlen(res) - i) + 1);
	if (!s)
		return (NULL);
	while (res[i])
		s[j++] = res[i++];
	s[j] = '\0';
	return (free(res), s);
}

static char	*get_lines(char	*res)
{
	int		i;
	char	*s;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] != '\n' && res[i])
		i++;
	if (res[i] == '\n')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (res[i] != '\n' && res[i])
	{
		s[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buff;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!res)
		res = ft_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (!(ft_strchr(res, '\n')) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(res), free(buff), res = NULL, NULL);
		buff[i] = '\0';
		res = strrjoin(res, buff);
	}
	free(buff);
	line = get_lines(res);
	res = next(res);
	return (line);
}
