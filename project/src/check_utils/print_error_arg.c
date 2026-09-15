/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:50:57 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 09:39:28 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_arg(char *str, char *arg)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '?')
		i++;
	if (!str[i])
	{
		print_error(str);
		return ;
	}
	write(2, str, i);
	write(2, arg, ft_strlen(arg));
	i++;
	write(2, &str[i], ft_strlen(&str[i]));
}
