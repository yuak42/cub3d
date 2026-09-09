/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:05:08 by yuak              #+#    #+#             */
/*   Updated: 2026/09/09 12:44:02 by yuak             ###   ########.fr       */
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
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), read_next_line(-1, NULL), 0);
	while (line)
	{
		if (is_map_line(line))
			return (free(line), close(fd), read_next_line(-1, NULL), 1);
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), close(fd), read_next_line(-1, NULL), 0);
	}
	print_error("Error\nThere is no map\n");
	read_next_line(-1, NULL);
	close(fd);
	return (0);
}
