/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:37:20 by aalami            #+#    #+#             */
/*   Updated: 2023/03/06 23:40:37 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = ft_new_node(data);
	node->next = stack->top;
	stack->top = node;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		data;

	if (empty_stack(stack))
		return (-1);
	data = stack->top->data;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	return (data);
}

void	index_update(t_stack *s)
{
	t_node	*tmp;
	int		i;

	if (empty_stack(s))
		return ;
	tmp = s->top;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*node;
	int		tmp_data;

	if (empty_stack(a) || !a->top->next || empty_stack(b) || !b->top->next)
		return ;
	tmp_data = pop(a);
	node = ft_new_node(tmp_data);
	tmp = a->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	index_update(a);
	tmp_data = pop(b);
	node = ft_new_node(tmp_data);
	tmp = b->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	index_update(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (empty_stack(a) || !a->top->next || empty_stack(b) || !b->top->next)
		return ;
	rrr_util(a);
	index_update(a);
	rrr_util(b);
	index_update(b);
}