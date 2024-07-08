/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:09:34 by sabras            #+#    #+#             */
/*   Updated: 2024/07/08 11:24:26 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack **stack)
{
	t_stack	*ptr;
	int		i;

	ptr = *stack;
	i = 1;
	while (ptr)
	{
		if (ft_is_max(stack, ptr))
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int	ft_find_min(t_stack **stack)
{
	t_stack	*ptr;
	int		i;

	ptr = *stack;
	i = 1;
	while (ptr)
	{
		if (ft_is_min(stack, ptr))
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int	ft_calculate_range(t_stack **stack)
{
	int	size;

	size = ft_stack_size(*stack);
	if (size <= 15)
		return (2);
	else if (size <= 100)
		return (15);
	else if (size <= 250)
		return (23);
	else if (size <= 500)
		return (34);
	return (45);
}

void	ft_repush_to_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;

	size = ft_stack_size(*stack_b);
	i = ft_find_max(stack_b);
	if (i <= (size / 2) + 1)
		while (--i)
			ft_rotate_stack(NULL, stack_b, "rb\n");
	else if (i > (size / 2) + 1)
		while (i++ <= size)
			ft_rotate_reverse_stack(NULL, stack_b, "rrb\n");
	ft_push_stack(stack_b, stack_a, "pa\n");
}

void	ft_swap_node(t_stack *node)
{
	int	tmp_value;
	int	tmp_index;

	if (ft_stack_size(node) <= 1)
		return ;
	tmp_value = node->value;
	tmp_index = node->index;
	node->value = node->next->value;
	node->index = node->next->index;
	node->next->value = tmp_value;
	node->next->index = tmp_index;
}
