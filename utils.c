/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:20:20 by sabras            #+#    #+#             */
/*   Updated: 2024/07/03 23:51:58 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_set_indexes(t_stack **stack_a, int *tab, int size)
{
	t_stack	*ptr;
	int		i;

	ptr = *stack_a;
	i = 0;
	while (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == ptr->value)
				ptr->index = i;
			i++;
		}
		ptr = ptr->next;
	}
}
