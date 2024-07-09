/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:17:14 by sabras            #+#    #+#             */
/*   Updated: 2024/07/09 13:18:29 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_rotate_stack(t_stack **stack, char *op)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		ft_swap_node(ptr);
		ptr = ptr->next;
	}
	ft_printf(op);
}

void	ft_rotate_reverse_stack(t_stack **stack, char *op)
{
	int		size;
	t_stack	*ptr;
	t_stack	*tmp;

	size = ft_stack_size(*stack);
	ptr = *stack;
	while (size - 1 > 1)
	{
		ptr = ptr->next;
		size--;
	}
	tmp = ptr->next;
	ptr->next = NULL;
	ft_stack_add_front(stack, tmp);
	ft_printf(op);
}
