/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:42:05 by aalami            #+#    #+#             */
/*   Updated: 2023/03/06 23:42:13 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr_util(t_stack *s)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = s->top;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = s->top;
	s->top = tmp;
	tmp2->next = NULL;
}
