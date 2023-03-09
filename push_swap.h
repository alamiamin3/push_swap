/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:01:03 by aalami            #+#    #+#             */
/*   Updated: 2023/03/09 19:27:14 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

int					check_nbr(char *str);
int					check_dup(char **arr);
int					is_int(char *str);
int					free_space(char **arr);
char				**check_args(char *buff, int argc, char **argv);
int					check_empty(int c, char **argv);
t_stack				*fill_stack(char **arr);
t_stack				*create_stack(void);
int					empty_stack(t_stack *stack);
void				push(t_stack *stack, int data);
t_node				*ft_new_node(int content);
int					pop(t_stack *stack);
void				sa(t_stack *stack);
void				ra(t_stack *stack);
void				rra(t_stack *stack);
void				pa(t_stack *stack_b, t_stack *stack_a);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				sb(t_stack *stack);
void				rb(t_stack *stack);
void				rrb(t_stack *stack);
int					get_args_num(char **arr);
int					is_sorted(char **arr);
void				ft_sort(int args, t_stack *a, t_stack *b);
int					get_max(t_stack *s);
int					get_index(t_stack *s, int data);
void				small_sort(t_stack *a);
int					stack_size(t_stack *stack);
void				sort_numbers(t_stack *a, t_stack *b);
int					get_min(t_stack *s);
int					*find_lenght(t_stack *a, int n);
int					*init_lis(int n);
int					*get_lis(t_stack *a, int n);
int					get_lis_max_index(int *lis, int n, int num);
int					get_lis_max(int *lis, int n);
t_node				*get_node_by_index(t_stack *a, int index);
int					get_lis_index(int *lis, int num, int max_index);
void				index_update(t_stack *s);
void				sort_large_numbers(t_stack *a, t_stack *b, int *lis,
						int max);
t_node				*get_higher_num(t_stack *a, int n);
t_node				*get_smaller(t_stack *s);
int					get_moves_to_top(t_stack *s, t_node *n);
void				rr(t_stack *a, t_stack *b);
void				rrr(t_stack *a, t_stack *b);
int					get_moves_to_a(t_stack *a, t_stack *b, t_node *n_b,
						t_node *n_a);
t_node				*best_move(t_stack *b, t_stack *a);
void				move_to_a(t_stack *a, t_stack *b);
void				move_to_top_a(t_stack *a, t_node *n);
void				move_to_top_b(t_stack *b, t_node *n);
void				final_sort(t_stack *a);
void				move_bottom(t_stack *a, t_stack *b, t_node *n_a,
						t_node *n_b);
void				move_up(t_stack *a, t_stack *b, t_node *n_a, t_node *n_b);
void				free_stack(t_stack *s);
void				rrr_util(t_stack *s);
int					check_if_sorted(t_stack *s);
#endif
