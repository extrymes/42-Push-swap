/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:19:59 by sabras            #+#    #+#             */
/*   Updated: 2024/06/24 15:19:08 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stcA;

	if (ac < 2)
		return (0);
	stcA = ft_parse_str(av[1]);
	if (!stcA.stack)
		return (1);
	if (!ft_check_stack(stcA))
		return (free(stcA.stack), 1);
	free(stcA.stack);
	return (0);
}
