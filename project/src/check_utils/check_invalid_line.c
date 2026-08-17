/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:14:50 by yuak              #+#    #+#             */
/*   Updated: 2026/08/17 08:25:56 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_invalid(char *line);
static int	check_map_line(char *line);


int	check_invalid_line(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	line = get_next_line(fd);
	while (line)
	{
		if (is_invalid(line))
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}

	return (0);
}

static int	is_invalid(char *line)
{
	if (ft_strncmp("\n", line, 2))
		return (0);
	else if (ft_strncmp("NO ", line, 3) || ft_strncmp("SO ", line, 3))
		return (0);
	else if (ft_strncmp("WE ", line, 3) || ft_strncmp("EA ", line, 3))
		return (0);
	else if (ft_strncmp("F ", line, 2) || ft_strncmp("C ", line, 2))
		return (0);
	else if (check_map_line(line))
		return (0);
	return (1);
}

static int	check_map_line(char *line)
{
	(void) line;
	return (1);
}