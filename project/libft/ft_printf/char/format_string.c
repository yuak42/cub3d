/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:58:08 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:57 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	format_string(char *str)
{
	int	n;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		n++;
	}
	return (n);
}
