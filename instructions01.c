/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:29:00 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 23:09:55 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **head_a, t_stack **head_b, int i)
{
	if (*head_b == NULL)
		return ;
	if (i)
		write(1, "pa\n", 3);
	*head_a = push(*head_a, (*head_b)->data, (*head_b)->index);
	*head_b = pop(*head_b);
}

void	pb(t_stack **head_a, t_stack **head_b, int i)
{
	if (*head_a == NULL)
		return ;
	if (i)
		write(1, "pb\n", 3);
	*head_b = push(*head_b, (*head_a)->data, (*head_a)->index);
	*head_a = pop(*head_a);
}

void	ra(t_stack **head_a, int i)
{
	t_stack	*current;
	t_stack	*head;
	t_stack	*second;

	head = *head_a;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	if (i)
		write(1, "ra\n", 3);
	second = head->next;
	head->next = NULL;
	*head_a = second;
	current = second;
	while (current->next)
		current = current->next;
	current->next = head;
}

void	rb(t_stack	**head_b, int i)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*current;

	head = *head_b;
	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	if (i)
		write(1, "rb\n", 3);
	second = head->next;
	head->next = NULL;
	*head_b = second;
	current = second;
	while (current->next)
		current = current->next;
	current->next = head;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
}
