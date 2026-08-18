/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:23:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/18 10:21:34 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_position_true(char *cub);
void	go_end_of_map(int fd);
int		is_end_of_file(int fd);

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
	if (!is_map_position_true(av[1]))
		return (print_error("Error\nMap position is wrong!"), 1);
	return (0);
}

int	is_map_position_true(char *cub)
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
			go_end_of_map(fd);
			if (!is_end_of_file(fd))
				return (close(fd), free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	go_end_of_map(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp("\n", line, 2))
			break ;	
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	is_end_of_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !ft_strncmp("\n", line, 2))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	return (0);
}