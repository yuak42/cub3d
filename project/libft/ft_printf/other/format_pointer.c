/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:06:19 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:52 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hex(unsigned long int ul, int *n);
static void	print_digit(unsigned long int ul);

int	format_pointer(void *pointer)
{
	int					n;
	unsigned long int	ul;

	if (pointer == (void *) 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = 2;
	write(1, "0x", 2);
	ul = (unsigned long int) pointer;
	print_hex(ul, &n);
	return (n);
}

static void	print_hex(unsigned long int ul, int *n)
{
	if (ul >= 16)
		print_hex(ul / 16, n);
	print_digit(ul);
	(*n)++;
}

static void	print_digit(unsigned long int ul)
{
	char	c;

	if (ul % 16 < 10)
		c = ul % 16 + '0';
	else
		c = ul % 16 - 10 + 'a';
	write(1, &c, 1);
}
