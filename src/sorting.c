/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:18:04 by sabras            #+#    #+#             */
/*   Updated: 2024/07/08 16:53:40 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3_nums(t_stack **stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (ft_is_max(stack, *stack))
		ft_rotate_stack(stack, NULL, "ra\n");
	else if (ft_is_max(stack, (*stack)->next))
		ft_rotate_reverse_stack(stack, NULL, "rra\n");
	if (!ft_is_sorted(stack))
		ft_swap_stack(stack, "sa\n");
}

void	ft_sort_4_nums(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;
	int		p;

	p = ft_find_min(stack_a);
	ptr = *stack_a;
	while (ptr)
	{
		if (ft_is_min(stack_a, ptr))
		{
			ft_push_stack(stack_a, stack_b, "pb\n");
			break ;
		}
		if (p < 3)
			ft_rotate_stack(stack_a, NULL, "ra\n");
		else
		{
			ft_rotate_reverse_stack(stack_a, NULL, "rra\n");
			ptr = *stack_a;
		}
	}
	ft_sort_3_nums(stack_a);
	ft_push_stack(stack_b, stack_a, "pa\n");
}

void	ft_sort_5_nums(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr;
	int		p;

	p = ft_find_min(stack_a);
	ptr = *stack_a;
	while (ptr)
	{
		if (ft_is_min(stack_a, ptr))
		{
			ft_push_stack(stack_a, stack_b, "pb\n");
			break ;
		}
		if (p < 3)
			ft_rotate_stack(stack_a, NULL, "ra\n");
		else
		{
			ft_rotate_reverse_stack(stack_a, NULL, "rra\n");
			ptr = *stack_a;
		}
	}
	ft_sort_4_nums(stack_a, stack_b);
	ft_push_stack(stack_b, stack_a, "pa\n");
}

void	ft_sort_more_5_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	range;
	int	size;

	range = ft_calculate_range(stack_a);
	while (*stack_a)
	{
		size = ft_stack_size(*stack_b);
		if ((*stack_a)->index < size)
		{
			ft_push_stack(stack_a, stack_b, "pb\n");
			ft_rotate_stack(NULL, stack_b, "rb\n");
		}
		else if ((*stack_a)->index <= (size + range))
			ft_push_stack(stack_a, stack_b, "pb\n");
		else
			ft_rotate_stack(stack_a, NULL, "ra\n");
	}
	while (*stack_b)
		ft_repush_to_stack(stack_a, stack_b);
}

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2 && ft_is_max(stack_a, *stack_a))
		ft_swap_stack(stack_a, "sa\n");
	else if (size == 3)
		ft_sort_3_nums(stack_a);
	else if (size == 4)
		ft_sort_4_nums(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5_nums(stack_a, stack_b);
	else
		ft_sort_more_5_nums(stack_a, stack_b);
}
