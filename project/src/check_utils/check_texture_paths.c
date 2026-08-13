/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:31:20 by yuak              #+#    #+#             */
/*   Updated: 2026/08/13 08:25:02 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_existence_and_uniqueness(char *id, char *cub);
static int	check_line(char *id, char *line, int *exits);

int	check_texture_paths(char *cub)
{
	if (check_existence_and_uniqueness("NO", cub))
		return (print_error("Error\nNO identifier is wrong!\n"));
	if (check_existence_and_uniqueness("SO", cub))
		return (print_error("Error\nSO identifier is wrong!\n"));
	if (check_existence_and_uniqueness("WE", cub))
		return (print_error("Error\nWE identifier is wrong!\n"));
	if (check_existence_and_uniqueness("EA", cub))
		return (print_error("Error\nEA identifier is wrong!\n"));
	return (0);
}

static int check_existence_and_uniqueness(char *id, char *cub)
{
	int		fd;
	char	*line;
	int		exist;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), -1);
	line = get_next_line(fd);
	exist = 0;
	while (line)
	{
		if (check_line(id, line, &exist))
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (exist == 0)
		return (1);
	return (0);
}

static int check_line(char *id, char *line, int *exist)
{
	char	**splitted;

	splitted = ft_split(line, ' ');
	if (!splitted)
		return (perror("Error"), 1);
	if (!ft_strncmp(id, splitted[0], ft_strlen(id) + 1))
		(*exist)++;
	if (*exist > 1)
		return (free_split(splitted), 1);	
	free_split(splitted);

	return (0);
}
