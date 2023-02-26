/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:18:52 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 18:11:34 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	check_int(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (i != ft_strlen(str))
		error_print();
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		error_print();
	return (ft_atoi(str));
}

void	check_repeated(char **str, int size)
{
	int	i;
	int	*tab;
	int	j;

	tab = malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	while (j < size)
	{
		tab[j] = ft_atoi(str[j]);
		j++;
	}
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] == tab[j] && i != j)
				error_print();
			j++;
		}
		i++;
	}
	free(tab);
}

int	check_sorted(t_stack **a)
{
	long	i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (i < lst_size(*a))
	{
		if (i == tmp->index)
		{
			i++;
			tmp = tmp->next;
		}
		else
			break ;
	}
	if (lst_size(*a) == i)
		return (0);
	return (1);
}
