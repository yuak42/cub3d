/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:31:20 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 08:57:57 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_existence_and_uniqueness(char *id, char *cub);
static int	check_line(char *id, char *line, int *exits);

int	check_texture_paths(char *cub)
{
	int	exit_flag;

	exit_flag = check_existence_and_uniqueness("NO", cub);
	if (exit_flag)
		return (exit_flag);
	exit_flag = check_existence_and_uniqueness("SO", cub);
	if (exit_flag)
		return (exit_flag);
	exit_flag = check_existence_and_uniqueness("WE", cub);
	if (exit_flag)
		return (exit_flag);
	exit_flag = check_existence_and_uniqueness("EA", cub);
	if (exit_flag)
		return (exit_flag);
	return (0);
}

static int check_existence_and_uniqueness(char *id, char *cub)
{
	int		fd;
	char	*line;
	int		exist;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	line = get_next_line(fd);
	exist = 0;
	while (line)
	{
		if (check_line(id, line, &exist))
			return (free(line), close(fd), 702);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (exist == 0)
	{
		print_error("Error\nThere is no identifir\n");
		return (701);
	}
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
	{
		print_error("Error\nThere are more than 1 path identifier\n");
		return (free_split(splitted), 1);	
	}
	free_split(splitted);

	return (0);
}
