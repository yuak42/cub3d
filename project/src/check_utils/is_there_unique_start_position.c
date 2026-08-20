/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_unique_start_position.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:22:29 by yuak              #+#    #+#             */
/*   Updated: 2026/08/20 14:30:23 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_start_position_number(char *line, int fd);

int	is_there_unique_start_position(char *cub)
{
	int		fd;
	char	*line;
	
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			if (get_start_position_number(line, fd) != 1)
			{
				print_error("Error\nThere are more than 1 start position\n");
				return (close(fd), 1);
			}
			else
				return (close(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

static int	get_start_position_number(char *line, int fd)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (line)
	{
		while (line[i])
		{
			if (line[i] == 'N' || line[i] == 'S')
				num++;
			else if (line[i] == 'W' || line[i] == 'E')
				num++;
			i++;
		}
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	return (num);
}
