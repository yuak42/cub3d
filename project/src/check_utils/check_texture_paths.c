/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:31:20 by yuak              #+#    #+#             */
/*   Updated: 2026/08/18 10:29:58 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_existence_and_uniqueness(char *id, char *cub);
static int	check_line(char *id, char *line, int *exits);

int	check_texture_paths(char *cub)
{
	if (check_existence_and_uniqueness("NO", cub))
		return (1);
	if (check_existence_and_uniqueness("SO", cub))
		return (1);
	if (check_existence_and_uniqueness("WE", cub))
		return (1);
	if (check_existence_and_uniqueness("EA", cub))
		return (1);
	if (check_existence_and_uniqueness("F", cub))
		return (1);
	if (check_existence_and_uniqueness("C", cub))
		return (1);
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
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (exist == 0)
	{
		print_error("Error\nThere is no identifier\n");
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
	if (get_splitted_size(splitted) != 2)
		return (ft_printf("line wrong %s", line), free_split(splitted), 1);
	if (*exist > 1)
	{
		print_error("Error\nThere are more than 1 path identifier\n");
		return (free_split(splitted), 702);	
	}
	free_split(splitted);
	return (0);
}
