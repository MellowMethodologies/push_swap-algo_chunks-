/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:48:38 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 17:23:56 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_it(size_t size, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
				break ;
			j++;
		}
		if (j == ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_print(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

int	return_lenght(int size, char **strs, int size_sep)
{
	int	i;
	int	len;

	i = -1;
	len = size_sep * -1;
	while (++i < size)
		len += size_sep + ft_strlen(strs[i]);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		len;

	if (!check_it(size, strs))
		error_print();
	if (size == 0)
	{
		res = malloc(sizeof(char *));
		return (res);
	}
	len = return_lenght(size, strs, ft_strlen(sep));
	i = -1;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (++i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if (i + 1 < size)
			res = ft_strcpy(res, sep);
	}
	*res = '\0';
	return (res - len);
}
