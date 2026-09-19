/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 10:10:43 by yuak              #+#    #+#             */
/*   Updated: 2026/09/19 10:11:55 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_file_format(char *cub)
{
	int	i;

	i = 0;
	while (cub[i])
		i++;
	if (i < 5)
		return (1);
	if (ft_strncmp(".cub", &cub[i - 4], 4))
		return (1);
	return (0);
}