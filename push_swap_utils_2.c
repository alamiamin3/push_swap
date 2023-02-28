/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:33:21 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 21:24:40 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *s)
{
	t_node	*tmp;
	int		min;

	tmp = s->top;
	min = s->top->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*get_node_by_index(t_stack *a, int index)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int	get_lis_index(int *lis, int num, int max_index)
{
	int	i;

	i = max_index;
	while (i >= 0)
	{
		if (lis[i] == num)
			break ;
		i--;
	}
	return (i);
}

void	move_up(t_stack *a, t_stack *b, t_node *n_a, t_node *n_b)
{
	if (get_moves_to_top(b, n_b) > get_moves_to_top(a, n_a))
	{
		while (a->top->data != n_a->data)
			rr(a, b);
		while (b->top->data != n_b->data)
			rb(b);
	}
	else
	{
		while (b->top->data != n_b->data)
			rr(a, b);
		while (a->top->data != n_a->data)
			ra(a);
	}
	pa(b, a);
}

void	move_bottom(t_stack *a, t_stack *b, t_node *n_a, t_node *n_b)
{
	if (get_moves_to_top(b, n_b) > get_moves_to_top(a, n_a))
	{
		while (a->top->data != n_a->data)
			rrr(a, b);
		while (b->top->data != n_b->data)
			rrb(b);
	}
	else
	{
		while (b->top->data != n_b->data)
			rrr(a, b);
		while (a->top->data != n_a->data)
			rra(a);
	}
	pa(b, a);
}
