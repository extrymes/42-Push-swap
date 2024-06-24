/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:15:15 by sabras            #+#    #+#             */
/*   Updated: 2024/06/24 15:01:53 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_check_duplicates(t_stack stc);

int	ft_check_stack(t_stack stc)
{
	if (!ft_check_duplicates(stc))
		return (ft_print_error("The stack contains duplicate numbers"), 0);
	return (1);
}

static int	ft_check_duplicates(t_stack stc)
{
	int	i;
	int	j;

	i = 0;
	while (i < stc.size)
	{
		j = 0;
		while (j < i)
		{
			if (stc.stack[i] == stc.stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
