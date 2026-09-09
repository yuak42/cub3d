/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:31:20 by yuak              #+#    #+#             */
/*   Updated: 2026/09/09 12:41:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_existence_and_uniqueness(char *id, char *cub);
static int	check_line(char *id, char *line, int *exits);

int	check_identifiers(char *cub)
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
	exist = 0;
	if (read_next_line(fd, &line))
		return (close(fd), perror("Error"), 1);
	while (line)
	{
		if (check_line(id, line, &exist))
			return (free(line), close(fd), 1);
		free(line);
		if (read_next_line(fd, &line))
			return (close(fd), perror("Error"), 1);
	}
	close(fd);
	read_next_line(-1, NULL);
	if (exist == 0)
		return (print_error_arg("Error\n? identifier is missing\n", id), 701);
	return (0);
}

static int check_line(char *id, char *line, int *exist)
{
	char	**splitted;

	splitted = ft_split(line, ' ');
	if (!splitted)
		return (perror("Error"), 1);
	if (!ft_strncmp(id, splitted[0], ft_strlen(id) + 1))
	{
		(*exist)++;
		if (get_splitted_size(splitted) != 2)
		{
			print_error_arg("Error\nWrong path format: ?", line);
			return (free_split(splitted), 1);
		}
	}
	if (*exist > 1)
	{
		print_error("Error\nThere are more than 1");
		print_error_arg(" ? path identifier\n", id);
		return (free_split(splitted), 702);
	}
	free_split(splitted);
	return (0);
}
