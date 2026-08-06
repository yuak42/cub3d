/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:00:24 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:55 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_unsigned(unsigned int u, int *n);

int	format_unsigned(unsigned int u)
{
	int	n;

	n = 0;
	print_unsigned(u, &n);
	return (n);
}

static void	print_unsigned(unsigned int u, int *n)
{
	char	c;

	if (u >= 10)
		print_unsigned(u / 10, n);
	c = u % 10 + '0';
	write(1, &c, 1);
	(*n)++;
}
