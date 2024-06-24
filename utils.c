/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:20:20 by sabras            #+#    #+#             */
/*   Updated: 2024/06/24 14:48:34 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"
#include "includes/colors.h"

t_stack	ft_init_stack(void)
{
	t_stack	stc;

	stc.stack = NULL;
	stc.size = 0;
	return (stc);
}

void	ft_print_error(char *error)
{
	ft_putstr(RED "Error\n");
	ft_putstr(error);
	ft_putstr("\n" RESET);
}
