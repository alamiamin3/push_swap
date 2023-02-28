/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:46:54 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 21:21:17 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_stack *a, t_node *n)
{
	int	mid;

	mid = (stack_size(a)) / 2;
	if (n->index <= mid)
	{
		while (a->top->data != n->data)
			ra(a);
	}
	else
	{
		while (a->top->data != n->data)
			rra(a);
	}
}

void	move_to_top_b(t_stack *b, t_node *n)
{
	int	mid;

	mid = (stack_size(b)) / 2;
	if (n->index <= mid)
	{
		while (b->top->data != n->data)
			rb(b);
	}
	else
	{
		while (b->top->data != n->data)
			rrb(b);
	}
}

int	get_moves_to_a(t_stack *a, t_stack *b, t_node *n_b, t_node *n_a)
{
	int	mid_a;
	int	mid_b;

	mid_a = (stack_size(a)) / 2 ;
	mid_b = (stack_size(b)) / 2;
	if (n_b->index <= mid_b && n_a->index <= mid_a)
	{
		if (get_moves_to_top(b, n_b) >= get_moves_to_top(a, n_a))
			return (n_a->index + (n_b->index - n_a->index));
		else
			return (n_b->index + (n_a->index - n_b->index));
	}
	else if (n_b->index > mid_b && n_a->index > mid_a)
	{
		if (get_moves_to_top(b, n_b) >= get_moves_to_top(a, n_a))
			return (get_moves_to_top(a, n_a) + (get_moves_to_top(b, n_b)
					- get_moves_to_top(a, n_a)));
		else
			return (get_moves_to_top(b, n_b) + (get_moves_to_top(a, n_a)
					- get_moves_to_top(b, n_b)));
	}
	else
		return ((get_moves_to_top(a, n_a) + get_moves_to_top(b, n_b)));
}

int	get_moves_to_top(t_stack *s, t_node *n)
{
	int	mid;

	mid = (stack_size(s)) / 2;
	if (n->index <= mid)
		return (n->index);
	else
		return (stack_size(s) - n->index);
}

int	stack_size(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	if (empty_stack(stack))
		return (0);
	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
