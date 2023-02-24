/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:28:49 by aalami            #+#    #+#             */
/*   Updated: 2023/02/24 15:21:16 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack   *fill_stack(char **arr)
{
	int	i;
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
	return stack;
}

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = ft_new_node(data);
	node->next = stack->top;
	stack->top = node;
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

int empty_stack(t_stack *stack)
{
    return stack->top == NULL;
}

int	pop(t_stack *stack)
{
	int data;
   t_node	*temp;

	if (empty_stack(stack))
		return -1;
	data = stack->top->data;
   temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void	index_update(t_stack *s)
{
	t_node	*tmp;
	int	i;

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
