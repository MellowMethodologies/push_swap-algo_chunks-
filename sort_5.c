/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:01:04 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 17:23:11 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **a, t_stack **b)
{
	int		min_pos;
	t_stack	*temp;
	t_stack	*min_node;

	min_node = node_position(a, 0);
	min_pos = position(a, 0);
	while ((*a)->index != min_node->index)
		if (min_pos <= 2)
			ra(a, 1);
	else
		rra(a, 1);
	pb(a, b, 1);
	temp = *a;
	while (temp)
	{
		temp->index = temp->index - 1;
		temp = temp ->next;
	}
	sort_4(a, b);
	pa(a, b, 1);
}
