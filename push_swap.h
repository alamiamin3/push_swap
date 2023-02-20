/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:01:03 by aalami            #+#    #+#             */
/*   Updated: 2023/02/20 22:10:55 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./lib/Libft/libft.h"

typedef struct s_node
{
	int	data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;


int		check_nbr(char *str);
int		check_dup(char **arr);
int		is_int(char *str);
int		free_space(char **arr);
char	**check_args(char *buff, int argc, char **argv);
int     check_empty(int c, char **argv);
t_stack   *fill_stack(char **arr);
t_stack	*create_stack(void);
int empty_stack(t_stack *stack);
void	push(t_stack *stack, int data);
t_node	*ft_new_node(int content);
int	pop(t_stack *stack);
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sb(t_stack *stack);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);
int	get_args_num(char **arr);
int	is_sorted(char **arr);
void	ft_sort(int	args, t_stack *a);
int	get_max(t_stack *s);
int	get_max_index(t_stack *s, int max);
void	small_sort(t_stack *a);
#endif
