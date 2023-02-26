/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:48:57 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 22:58:31 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;
	char	**str;
	char	*join;

	if (ac == 1)
		exit(1);
	head_b = NULL;
	head_a = NULL;
	i = 0;
	join = ft_strjoin(ac - 1, av + 1, " ");
	str = ft_split(join, ' ');
	free(join);
	check_repeated(str, ac - 1);
	while (str[i])
		head_a = push_back(head_a, check_int(str[i++]), 0);
	doer(&head_a, &head_b, i);
	free_lst(&head_a);
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}
