/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:02:25 by aalami            #+#    #+#             */
/*   Updated: 2023/02/23 19:29:35 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*find_lenght(int *arr, int n)
{
	int 	*lis;
	int	len;
	int	size;
	int	i; // check previews cells of the current cell
	int	j; // check array's cells

	len = 1;
	size = 0;
	lis = malloc(sizeof(int) * n);
	j = 1;
	while (size < n)
	{
		lis[size] = 1;
		size ++;
	}
	while (j < n)
	{
		i = 0;
		while (i < j)
		{
			if (arr[i] < arr[j] && lis[j] <= lis[i])
			{
				lis[j] = lis[i] + 1;
				len = lis[j];
			}
			i++;
		}
		j++;
	}
	return (lis);
}

int	main()
{
	int arr[12] = {40, 67, 95, 79, 7, 9, 19, 59, 51, 76, 54, 84};
	int i;
	int *lis = find_lenght(arr, 12);
	i = 0;
	while (i < 12)
	{
		printf("%d    ",lis[i]);
		i++;
	}
		printf("\n");
	
}
