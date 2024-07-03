/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:16:46 by sabras            #+#    #+#             */
/*   Updated: 2024/07/01 00:05:43 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
int		ft_isdigit(char c);
int		ft_atoi(char *s, int *tab);
char	**ft_split(char *s, char c);

#endif
