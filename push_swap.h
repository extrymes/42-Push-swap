/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:15:09 by sabras            #+#    #+#             */
/*   Updated: 2024/07/08 11:43:00 by sabras           ###   ########.fr       */
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
t_stack	*ft_init_stack(int value);
int		ft_stack_size(t_stack *stack);
void	ft_stack_add_front(t_stack **stack, t_stack *node);
void	ft_free_stack(t_stack **stack);

// Checkers
int		ft_check_str(char *s);
int		*ft_check_args(int ac, char **av, int size);
int		ft_check_duplicates(int *tab, int size);

// Parsing
t_stack	**ft_tab_to_stack(int *tab, int size);
int		ft_count_nums(int ac, char **av);
void	ft_split_nums(char *str, int idx, int *tab);

// Sorting
void	ft_sort_3_nums(t_stack **stack);
void	ft_sort_4_nums(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_5_nums(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_more_5_nums(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b);

// Rules
void	ft_swap_stack(t_stack **stack, char *op);
void	ft_push_stack(t_stack **stack_from, t_stack **stack_to, char *op);
void	ft_rotate_stack(t_stack **stack_a, t_stack **stack_b, char *op);
void	ft_rotate_reverse_stack(t_stack **stack_a, t_stack **stack_b, char *op);

// Utils
void	ft_sort_tab(int *tab, int size);
void	ft_set_indexes(t_stack **stack_a, int *tab, int size);
int		ft_is_sorted(t_stack **stack);
int		ft_is_max(t_stack **stack, t_stack *node);
int		ft_is_min(t_stack **stack, t_stack *node);

// Utils 2
int		ft_find_max(t_stack	**stack);
int		ft_find_min(t_stack	**stack);
int		ft_calculate_range(t_stack **stack);
void	ft_repush_to_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_swap_node(t_stack *node);

// Error
void	ft_throw_error(void);

#endif
