/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:24:49 by aalami            #+#    #+#             */
/*   Updated: 2022/10/22 10:56:49 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	ret = 0;
	while (tmp != NULL)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
