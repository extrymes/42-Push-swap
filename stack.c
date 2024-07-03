/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:19:55 by sabras            #+#    #+#             */
/*   Updated: 2024/07/03 23:23:37 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = stack;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	if (!*stack)
	{
		*stack = new;
		(*stack)->next = NULL;
	}
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*next;

	ptr = *stack;
	while (ptr)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	free(stack);
}
