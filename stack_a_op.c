/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:02:39 by aalami            #+#    #+#             */
/*   Updated: 2023/02/25 12:30:03 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
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
	write(1,"sa\n",3);
}

void	ra(t_stack *stack)
{
	t_node	*tmp;
	t_node	*node;
	int	tmp_data;

	if (empty_stack(stack) || !stack->top->next)
		return ;
	tmp_data = pop(stack);
	node = ft_new_node(tmp_data);
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	write(1,"ra\n",3);
}

void	rra(t_stack *stack)
{
	t_node	*tmp;
	int	tmp_data;

	if (empty_stack(stack) || !stack->top->next)
		return ;
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp_data = tmp->next->data;
	tmp->next = NULL;
	free(tmp->next);
	push(stack, tmp_data);
	write(1,"rra\n",4);
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	if (empty_stack(stack_b))
		return ;
	push(stack_a, stack_b->top->data);
	pop(stack_b);
	index_update(stack_a);
	index_update(stack_b);
	write(1,"pa\n",3);
}
// 152 158 255  560 654 794 836  