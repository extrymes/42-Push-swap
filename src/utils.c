/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:20:20 by sabras            #+#    #+#             */
/*   Updated: 2024/07/09 13:00:03 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		if (ptr->next && (ptr->index > ptr->next->index))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_is_max(t_stack **stack, t_stack *node)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		if (node->index < ptr->index)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_is_min(t_stack **stack, t_stack *node)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		if (node->index > ptr->index)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
