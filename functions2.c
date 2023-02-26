/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:42:54 by sbadr             #+#    #+#             */
/*   Updated: 2023/01/08 05:06:11 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_it(t_stack **a, t_stack **b, t_vars *vars)
{
	vars->j = 0;
	if (vars->pos < lst_size(*a) / 2)
		while (vars->j++ < vars->pos)
			ra(a, 1);
	else
		while (vars->j++ < lst_size(*a) - vars->pos)
			rra(a, 1);
	if ((*a)->index >= vars->chunk - (vars->deep / 2))
	{
		pb(a, b, 1);
		rb(b, 1);
	}
	else
		pb(a, b, 1);
}

void	sorted(t_stack **a, t_stack **b, int chunk, int deep)
{
	t_stack	*tmp;
	t_vars	vars;

	vars.j = 0;
	vars.l = 0;
	while (vars.l++ < deep && *a)
	{
		tmp = *a;
		vars.pos = 0;
		while (tmp && tmp->index > chunk)
		{
			tmp = tmp->next;
			vars.pos++;
		}
		vars.chunk = chunk;
		vars.deep = deep;
		do_it(a, b, &vars);
	}
}

void	stacker(t_stack **a, t_stack **b, int size)
{
	t_stack	*temp;
	int		chunk;
	int		deep;

	deep = lst_size(*a) / size;
	chunk = lst_size(*a) / size;
	temp = *a;
	while (lst_size(*a))
	{
		sorted(a, b, chunk, deep);
		if (lst_size(*a) <= 100 && size == 9)
			deep = 20;
		chunk += deep;
	}
}

void	indexer(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	if (!tmp ->next)
		return ;
	while (tmp)
	{
		tmp1 = *a;
		while (tmp1)
		{
			if (tmp->data > tmp1->data)
					tmp->index++;
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
