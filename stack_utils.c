/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:52:50 by aalami            #+#    #+#             */
/*   Updated: 2023/02/28 21:59:20 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **arr)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = create_stack();
	while (arr[i + 1])
		i++;
	while (i >= 0)
	{
		push(stack, ft_atoi(arr[i]));
		stack->top->index = i;
		i--;
	}
	return (stack);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->top = NULL;
	return (stack);
}

t_node	*ft_new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_list));
	if (!(node))
		return (0);
	node->data = content;
	node->next = NULL;
	return (node);
}

int	empty_stack(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	else
		return (0);
}
