/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:21:35 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 23:21:56 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack));
		(*stack) = tmp;
	}
}
