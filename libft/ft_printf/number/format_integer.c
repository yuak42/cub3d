/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:59:54 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:55 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	print_integer(int integer, int *n);

int	format_integer(int integer)
{
	int	n;

	n = 0;
	print_integer(integer, &n);
	return (n);
}

static void	print_integer(int integer, int *n)
{
	char	*s;

	s = ft_itoa(integer);
	write(1, s, ft_strlen(s));
	(*n) += ft_strlen(s);
	free(s);
}
