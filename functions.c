/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:37:30 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/07 20:56:39 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push(t_stack *head, int data, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = index;
	new_node->next = head;
	return (new_node);
}

t_stack	*ft_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*push_back(t_stack *head, long data, int index)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = index;
	new_node->next = NULL;
	if (!head)
		return (new_node);
	last = ft_last(head);
	last->next = new_node;
	return (head);
}

t_stack	*pop(t_stack *head)
{
	t_stack	*popped;

	if (head == NULL)
		return (NULL);
	popped = head;
	head = head->next;
	free(popped);
	return (head);
}

int	lst_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
