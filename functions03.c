/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:31:05 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 22:59:24 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_index(t_stack *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == highest_index(*stack_b)
			|| (*stack_b)->index == highest_index(*stack_b) - 1)
			pa(stack_a, stack_b, 1);
		else if (finder(stack_b, highest_index(*stack_b))
			> lst_size(*stack_b) / 2)
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				rrb(stack_b, 1);
		else
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				rb(stack_b, 1);
		if (lst_size(*stack_a) > 1
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 1);
	}
}

int	finder(t_stack **stack, int pos)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp)
	{
		if (tmp->index == pos)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	doer(t_stack **head_a, t_stack **head_b, int ac)
{
	indexer(head_a);
	if (check_sorted(head_a))
	{
		if (ac <= 3)
			sort_3(head_a);
		else if (ac == 4)
			sort_4(head_a, head_b);
		else if (ac == 5)
			sort_5(head_a, head_b);
		else if (ac < 100)
			stacker(head_a, head_b, 3);
		else if (ac == 100)
			stacker(head_a, head_b, 5);
		else if (ac > 100)
			stacker(head_a, head_b, 9);
		push_back_to_a(head_a, head_b);
	}
	else
		return ;
}
