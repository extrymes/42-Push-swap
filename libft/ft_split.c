/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:24:42 by sabras            #+#    #+#             */
/*   Updated: 2024/06/21 13:48:42 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	size_t	ft_count_tabs(char *str, char sep)
{
	size_t	tabs_count;
	size_t	in_str;
	size_t	i;

	tabs_count = 0;
	in_str = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && !in_str)
		{
			tabs_count++;
			in_str = 1;
		}
		else if (str[i] == sep)
			in_str = 0;
		i++;
	}
	return (tabs_count);
}

void	ft_free_tab(char **tab, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
		free(tab[i++]);
	free(tab);
}

void	ft_insert_tab(char **tab, char *str, size_t len, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		tab[idx][i] = str[i];
		i++;
	}
	tab[idx][i] = '\0';
}

int	ft_insert_tabs(char	**tab, char *str, char sep)
{
	size_t	idx;
	size_t	i;
	size_t	j;

	idx = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			j = 0;
			while (str[i + j] && str[i + j] != sep)
				j++;
			tab[idx] = malloc((j + 1) * sizeof(char));
			if (!tab[idx])
				return (ft_free_tab(tab, idx), 0);
			ft_insert_tab(tab, str + i, j, idx++);
			i += j - 1;
		}
		i++;
	}
	tab[idx] = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	size_t	tabs_count;

	if (!s)
		return (NULL);
	tabs_count = ft_count_tabs(s, c);
	tab = malloc((tabs_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_insert_tabs(tab, s, c))
		return (NULL);
	return (tab);
}
