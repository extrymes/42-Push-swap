/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:16:53 by sabras            #+#    #+#             */
/*   Updated: 2024/06/24 15:11:59 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

static t_stack	ft_convert_tab(char **tab);
static int		ft_check_tab(char **tab);
static int		ft_get_tab_size(char **tab);
static void		ft_free_tab(char **tab);

t_stack	ft_parse_str(char *str)
{
	t_stack	a;
	char	**tab;

	a = ft_init_stack();
	tab = ft_split(str, ' ');
	if (!tab)
		return (ft_print_error("Failed to allocate memory for tab"), a);
	if (!tab[0])
		return (ft_print_error("The stack is empty"), a);
	if (!ft_check_tab(tab))
		return (ft_print_error("The stack must contain numbers only"),
			ft_free_tab(tab), a);
	a = ft_convert_tab(tab);
	if (!a.stack)
		return (ft_free_tab(tab), a);
	ft_free_tab(tab);
	return (a);
}

static t_stack	ft_convert_tab(char **tab)
{
	t_stack	a;
	int	i;

	a.stack = malloc(ft_get_tab_size(tab) * sizeof(int));
	if (!a.stack)
		return (ft_print_error("Failed to allocate memory for stack"), a);
	i = 0;
	while (tab[i])
	{
		a.stack[i] = ft_atoi(tab[i]);
		i++;
	}
	a.size = i;
	return (a);
}

static int	ft_check_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '+' || tab[i][j] == '-')
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_get_tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
