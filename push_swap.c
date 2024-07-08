/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:19:59 by sabras            #+#    #+#             */
/*   Updated: 2024/07/04 03:07:10 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		*tab;
	int		size;

	if (ac < 2)
		return (0);
	size = ft_count_nums(ac, av);
	tab = ft_check_args(ac, av, size);
	stack_a = ft_tab_to_stack(tab, size);
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return (ft_free_stack(stack_a), free(tab), ft_throw_error(), 1);
	*stack_b = NULL;
	if (!ft_is_sorted(stack_a))
		ft_sort_stacks(stack_a, stack_b);
	return (ft_free_stack(stack_a), free(stack_b), 0);
}
