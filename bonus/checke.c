/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checke.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:55:35 by aalami            #+#    #+#             */
/*   Updated: 2023/03/06 23:48:04 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	checker(char **arr)
{
	char	*line;
	t_stack *a;
	t_stack *b;

	line = get_next_line(0);
	a = fill_stack(arr);
	b = create_stack();
	while (line)
	{
		if (ft_strncmp(line,"sa",2) == 0)
			sa(a);
		else if ((ft_strncmp(line,"ra",2) == 0))
			ra(a);
		else if ((ft_strncmp(line,"rra",3) == 0))
			rra(a);
		else if ((ft_strncmp(line,"pb",2) == 0))
			pb(a,b);
		else if ((ft_strncmp(line,"sb",2) == 0))
			sb(b);
		else if ((ft_strncmp(line,"rb",2) == 0))
			rb(b);
		else if ((ft_strncmp(line,"rrb",3) == 0))
			rrb(b);
		else if ((ft_strncmp(line,"pa",2) == 0))
			pa(b, a);
		else if ((ft_strncmp(line,"rr",2) == 0))
			rr(a, b);
		else if ((ft_strncmp(line,"rrr",3) == 0))
			rrr(a, b);
	}
	
}
int	main(int argc, char **argv)
{
	char	**arr;
	char	*buff;
	char	*line;

	if (argc > 1)
	{
		buff = get_args(argc, argv);
		arr = check_args(buff, argc, argv);
		free(buff);
		if (arr)
			push_swap(arr);
		else
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	else
		exit(EXIT_SUCCESS);
}