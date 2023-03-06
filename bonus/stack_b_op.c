/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:32:42 by aalami            #+#    #+#             */
/*   Updated: 2023/03/06 23:36:29 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_stack *stack)
{
	int	tmp;

	if (empty_stack(stack) || !stack->top->next)
		return ;
	else
	{
		tmp = stack->top->data;
		stack->top->data = stack->top->next->data;
		stack->top->next->data = tmp;
	}
	index_update(stack);
}

void	rb(t_stack *stack)
{
	t_node	*tmp;
	t_node	*node;
	int		tmp_data;

	if (empty_stack(stack) || !stack->top->next)
		return ;
	tmp_data = pop(stack);
	node = ft_new_node(tmp_data);
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	index_update(stack);
}

void	rrb(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (empty_stack(stack) || !stack->top->next)
		return ;
	tmp = stack->top;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack->top;
	stack->top = tmp;
	tmp2->next = NULL;
	index_update(stack);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (empty_stack(stack_a))
		return ;
	push(stack_b, stack_a->top->data);
	pop(stack_a);
	index_update(stack_b);
	index_update(stack_a);
}
