/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:16:53 by sabras            #+#    #+#             */
/*   Updated: 2024/07/03 23:42:42 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**ft_tab_to_stack(int *tab, int size)
{
	t_stack	**stack_a;
	t_stack	*new_node;
	t_stack	*ptr;
	int		i;

	stack_a = malloc(size * sizeof(t_stack *));
	if (!stack_a)
		return (free(tab), ft_throw_error(), NULL);
	ptr = NULL;
	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_init_stack(tab[i]);
		new_node->next = ptr;
		ptr = new_node;
		stack_a[i] = ptr;
		i--;
	}
	ft_sort_tab(tab, size);
	ft_set_indexes(stack_a, tab, size);
	return (free(tab), stack_a);
}

int	ft_count_nums(int ac, char **av)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
			ft_throw_error();
		total += ft_check_str(av[i]);
		i++;
	}
	return (total);
}

void	ft_split_nums(char *str, int idx, int *tab)
{
	char	**res;
	int		i;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
		tab[idx++] = ft_atoi(res[i++], tab);
	while (--i >= 0)
		free(res[i]);
	free(res);
}
