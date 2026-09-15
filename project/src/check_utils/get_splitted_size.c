/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_splitted_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:32:15 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 09:39:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	get_splitted_size(char **splitted)
{
	size_t	i;

	i = 0;
	while (*splitted)
	{
		i++;
		splitted++;
	}
	return (i);
}
