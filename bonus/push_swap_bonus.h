/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:08:27 by aalami            #+#    #+#             */
/*   Updated: 2023/03/09 19:26:17 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../lib/Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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
void				index_update(t_stack *s);
void				rr(t_stack *a, t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				free_stack(t_stack *s);
void				rrr_util(t_stack *s);
void				handle_error(char **arr, t_stack *a, t_stack *b);
int					handle_a(char *line, t_stack *a, t_stack *b);
int					handle_b(char *line, t_stack *a, t_stack *b);
int					handle_mutual(char *line, t_stack *a, t_stack *b);
void				execute_actions(char *line, char **arr, t_stack *a,
						t_stack *b);
int					free_all(char **arr, t_stack *a, t_stack *b);
int					ft_strcmp(char *s1, char *s2);
#endif
