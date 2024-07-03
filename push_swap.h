/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:15:09 by sabras            #+#    #+#             */
/*   Updated: 2024/07/03 23:59:34 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

// Stack definition
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Stack
t_stack	*ft_init_stack(int content);
int		ft_stack_size(t_stack *lst);
void	ft_stack_add_front(t_stack **lst, t_stack *new);
void	ft_free_stack(t_stack **stack);

// Checkers
int		ft_check_str(char *s);
int		*ft_check_args(int ac, char **av, int size);
int		ft_check_duplicates(int *tab, int size);

// Parsing
t_stack	**ft_tab_to_stack(int *tab, int size);
int		ft_count_nums(int ac, char **av);
void	ft_split_nums(char *str, int idx, int *tab);

// Utils
void	ft_set_indexes(t_stack **stack_a, int *tab, int size);
void	ft_sort_tab(int *tab, int size);

// Error
void	ft_throw_error(void);

#endif