/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:17:14 by sabras            #+#    #+#             */
/*   Updated: 2024/07/08 10:47:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_reverse(t_stack **stack);

void	ft_swap_stack(t_stack **stack, char *op)
{
	if (stack)
		ft_swap_node(*stack);
	ft_printf(op);
}

void	ft_push_stack(t_stack **stack_from, t_stack **stack_to, char *op)
{
	t_stack	*tmp;

	tmp = (*stack_from)->next;
	ft_stack_add_front(stack_to, *stack_from);
	*stack_from = tmp;
	ft_printf(op);
}

void	ft_rotate_stack(t_stack **stack_a, t_stack **stack_b, char *op)
{
	t_stack	*ptr;

	if (stack_a)
	{
		ptr = *stack_a;
		while (ptr)
		{
			ft_swap_node(ptr);
			ptr = ptr->next;
		}
	}
	if (stack_b)
	{
		ptr = *stack_b;
		while (ptr)
		{
			ft_swap_node(ptr);
			ptr = ptr->next;
		}
	}
	ft_printf(op);
}

void	ft_rotate_reverse_stack(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (stack_a)
		ft_rotate_reverse(stack_a);
	if (stack_b)
		ft_rotate_reverse(stack_b);
	ft_printf(op);
}

static void	ft_rotate_reverse(t_stack **stack)
{
	int		size;
	t_stack	*temp1;
	t_stack	*temp2;

	size = ft_stack_size(*stack);
	temp1 = *stack;
	while (size - 1 > 1)
	{
		temp1 = temp1->next;
		size--;
	}
	temp2 = temp1->next;
	temp1->next = NULL;
	ft_stack_add_front(stack, temp2);
}
