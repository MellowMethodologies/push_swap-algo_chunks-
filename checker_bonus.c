/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:29:06 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 23:44:09 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pfft(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(str, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sa(a, 0);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b);
	else
		error_print();
	free(str);
}

void	switch_instruction(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		pfft(str, a, b);
	}
}

void	point_it(t_stack **a)
{
	if (!check_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	indexer(&head_a);
	switch_instruction(&head_a, &head_b);
	point_it(&head_a);
	free_lst(&head_a);
	free_lst(&head_b);
	while (i >= 0)
		free(str[i--]);
	free(str);
}
