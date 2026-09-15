/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:36:03 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 09:39:01 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line(char *line);
static int	check_color(char *color);
static int	check_color_num(char **splitted);

int	check_colors(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), read_next_line(-1, NULL));
	while (line)
	{
		if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
		{
			if (check_line(line))
				return (free(line), close(fd), read_next_line(-1, NULL));
		}
		free(line);
		if (read_next_line(fd, &line))
			return (close(fd), perror("Error"), read_next_line(-1, NULL));
	}
	read_next_line(-1, NULL);
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
		return (print_error_arg("Error\nColor pattern wrong: ?\n", line), 1);
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
	{
		print_error_arg("Error\nColor format wrong: ?\n", color);
		return (free_split(splitted), 1);
	}
	if (check_color_num(splitted))
		return (free_split(splitted), 1);
	free_split(splitted);
	return (0);
}

static int	check_color_num(char **splitted)
{
	int		i;
	char	*color;
	int		temp;

	while (*splitted)
	{
		i = 0;
		color = *splitted;
		if (color[i] == '0' && color[i + 1] != '\0')
			return (print_error("Error\nNumber should be decimal\n"), 1);
		while (color[i])
		{
			if (!ft_isdigit(color[i]))
				return (print_error("Error\nNumber is not natural\n"), 1);
			i++;
		}
		temp = ft_atoi(color);
		if (temp > 255)
			return (print_error("Error\nNumber is outside of range\n"), 1);
		splitted++;
	}
	return (0);
}
