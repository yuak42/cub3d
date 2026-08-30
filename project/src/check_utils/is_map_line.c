/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:18:37 by yuak              #+#    #+#             */
/*   Updated: 2026/08/30 15:26:46 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	if (*line == '\n')
		return (0);
	while (*line)
	{
		if (*line == ' ' || *line == '1' || *line == '0')
		{
			line++;
			continue;
		}
		if (*line == 'N' || *line == 'W' || *line == 'S')
		{
			line++;
			continue;
		}
		if (*line == 'E' || *line == '\n')
		{
			line++;
			continue;
		}
		return (0);
	}
	return (1);
}
