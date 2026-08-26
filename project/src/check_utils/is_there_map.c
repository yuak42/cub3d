/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:05:08 by yuak              #+#    #+#             */
/*   Updated: 2026/08/24 10:05:15 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_map(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	print_error("Error\nThere is no map\n");
	close(fd);
	return (0);
}
