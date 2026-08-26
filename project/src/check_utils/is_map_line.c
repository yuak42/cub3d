/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:18:37 by yuak              #+#    #+#             */
/*   Updated: 2026/08/26 13:30:29 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_map_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (0);
	if (!ft_strncmp(line, "SO ", 3))
		return (0);
	if (!ft_strncmp(line, "WE ", 3))
		return (0);
	if (!ft_strncmp(line, "EA ", 3))
		return (0);
	if (!ft_strncmp(line, "F ", 2))
		return (0);
	if (!ft_strncmp(line, "C ", 2))
		return (0);
	if (line[0] == '\n')
		return (0);
	return (1);
}
