/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:09:30 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:17 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
			write(fd, "-", 1);
		ft_putnbr((long int)n, fd);
	}
}

static void	ft_putnbr(long int n, int fd)
{
	char	c;

	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
