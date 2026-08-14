/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:36:03 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 20:52:58 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line(char *line);
static int	check_color(char *color);

int	check_colors(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
		{
			if (check_line(line))
				return (free(line), close(fd), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	check_line(char *line)
{
	char	*trimmed;
	char	**splitted;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return (perror("Error"), 1002);
	splitted = ft_split(trimmed, ' ');
	if (!splitted)
		return (perror("Error"), 1001);
	if (get_splitted_size(splitted) != 2)
	{
		free_split(splitted);
		free(trimmed);
		return (print_error("Error\nColor wrong!\n"), 1);
	}
	if (check_color(splitted[1]))
		return (free_split(splitted), free(trimmed), 1);
	free_split(splitted);
	free(trimmed);
	return (0);
}

static int	check_color(char *color)
{
	char	**splitted;

	splitted = ft_split(color, ',');
	if (!splitted)
		return (1001);
	if (get_splitted_size(splitted) != 3)
		return (free_split(splitted), print_error("Error\nColor wrong\n"), 1);
	free_split(splitted);
	return (0);
}