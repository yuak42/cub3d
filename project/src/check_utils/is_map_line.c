/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:18:37 by yuak              #+#    #+#             */
/*   Updated: 2026/08/30 15:35:56 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_char(char c);

int	is_map_line(char *line)
{
	if (*line == '\n')
		return (0);
	while (*line)
	{
		if (is_map_char(*line))
		{
			line++;
			continue;
		}
		return (0);
	}
	return (1);
}

static int	is_map_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == '\n')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}