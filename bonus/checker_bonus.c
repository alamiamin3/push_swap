/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:55:35 by aalami            #+#    #+#             */
/*   Updated: 2023/03/07 22:02:16 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
void	leaks(void)
{
	system("leaks checker");
}

int	check_empty(int c, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (argv[i][j] && ((argv[i][j] >= '\t' && argv[i][j] <= '\r')
				|| argv[i][j] == ' '))
			j++;
		if (j == (int)ft_strlen(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*get_args(int argc, char **argv)
{
	int		args;
	char	*buff;
	char	*buff2;
	int		i;

	args = argc - 1;
	buff2 = ft_strdup("");
	i = 1;
	while (args)
	{
		buff = ft_strjoin(buff2, " ");
		free(buff2);
		buff2 = ft_strjoin(buff, argv[i]);
		i++;
		args--;
		free(buff);
	}
	return (buff2);
}
int	check_if_sorted(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!empty_stack(b) || empty_stack(a))
		return (0);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
	
}
void	checker(char **arr)
{
	t_stack *a;
	t_stack *b;
	char	*line;

	line = get_next_line(0);
	a = fill_stack(arr);
	b = create_stack();
	while (line)
	{
		if ((strcmp(line,"sa\n") == 0))
			sa(a);
		else if ((strcmp(line,"ra\n") == 0))
			ra(a);
		else if ((strcmp(line,"rra\n") == 0))
			rra(a);
		else if ((strcmp(line,"pb\n") == 0))
			pb(a,b);
		else if ((strcmp(line,"sb\n") == 0))
			sb(b);
		else if ((strcmp(line,"rb\n") == 0))
			rb(b);
		else if ((strcmp(line,"rrb\n") == 0))
			rrb(b);
		else if ((strcmp(line,"pa\n") == 0))
			pa(b, a);
		else if ((strcmp(line,"rr\n") == 0))
			rr(a, b);
		else if ((strcmp(line,"rrr\n") == 0))
			rrr(a, b);
		else
		{
			write(1, "ERROR\n", 6);
			free_space(arr);
			free_stack(a);
			free_stack(b);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(0);
	}
	if (check_if_sorted(a, b))
	write(1, "OK\n", 3);
		
	else
		write(1, "KO\n", 3);
	free_space(arr);
	free_stack(a);
	free_stack(b);
}
int	main(int argc, char **argv)
{
	char	**arr;
	char	*buff;
	// atexit(leaks);
	if (argc > 1)
	{
		buff = get_args(argc, argv);
		arr = check_args(buff, argc, argv);
		free(buff);
		if (arr)
			checker(arr);
		else
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	else
		exit(EXIT_SUCCESS);
}