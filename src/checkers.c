/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:15:15 by sabras            #+#    #+#             */
/*   Updated: 2024/07/09 12:49:23 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_check_duplicates(int *tab, int size);

int	ft_check_str(char *s)
{
	int	nums;
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
			|| ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1])))
			return (0);
		i++;
	}
	nums = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != ' ')
			i++;
		if (s[i - 1] && s[i - 1] != ' ')
			nums++;
		while (s[i] && s[i] == ' ')
			i++;
	}
	return (nums);
}

int	*ft_check_args(int ac, char **av, int size)
{
	int	*tab;
	int	nums;
	int	i;
	int	j;

	tab = malloc(size * sizeof(int));
	if (!tab)
		ft_throw_error();
	i = 1;
	j = 0;
	while (i < ac)
	{
		nums = ft_check_str(av[i]);
		if (nums == 0)
			return (free(tab), ft_throw_error(), NULL);
		else if (nums == 1)
			tab[j] = ft_atoi(av[i], tab);
		else
			ft_split_nums(av[i], j, tab);
		i++;
		j += nums;
	}
	if (!ft_check_duplicates(tab, size))
		return (free(tab), ft_throw_error(), NULL);
	return (tab);
}

static int	ft_check_duplicates(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
