/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:35:28 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 23:09:52 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **head_a, int i)
{
	t_stack	*head;
	t_stack	*second;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	if (i)
		write(1, "sa\n", 3);
	head = *head_a;
	second = head->next;
	head->next = second->next;
	second->next = head;
	*head_a = second;
}

void	sb(t_stack **head_b, int i)
{
	t_stack	*second;
	t_stack	*head;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	if (i)
		write(1, "sb\n", 3);
	head = *head_b;
	second = head->next;
	head->next = second->next;
	second->next = head;
	*head_b = second;
}

void	rra(t_stack **head_a, int i)
{
	t_stack	*last;
	t_stack	*current;

	current = *head_a;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	if (i)
		write(1, "rra\n", 4);
	while (current->next->next != NULL)
	{
	current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = *head_a;
	*head_a = last;
}

void	rrb(t_stack **head_b, int i)
{
	t_stack	*current;
	t_stack	*last;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	if (i)
		write(1, "rrb\n", 4);
	current = *head_b;
	while (current->next->next != NULL)
	{
	current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = *head_b;
	*head_b = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
}
