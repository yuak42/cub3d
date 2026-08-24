/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:23:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/24 10:04:23 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_map(char *cub);

int check_input(int ac, char **av)
{
	if (ac != 2)
		return (print_error("Error\nInput number wrong!\n"), 700);
	if (check_texture_paths(av[1]))
		return (1);
	if (check_colors(av[1]))
		return (1);
	if (check_invalid_line(av[1]))
		return (1);
	if (!is_there_map(av[1]))
		return (1);
	if (!is_map_position_true(av[1]))
		return (print_error("Error\nMap position is wrong!"), 1);
	if (!is_start_position_correct(av[1]))
		return (1);
	return (0);
}

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
