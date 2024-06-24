/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:15:09 by sabras            #+#    #+#             */
/*   Updated: 2024/06/24 14:58:30 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

// Parsing
t_stack	ft_parse_str(char *str);

// Checkers
int		ft_check_stack(t_stack stc);

// Utils
t_stack	ft_init_stack(void);
void	ft_print_error(char *error);

#endif
