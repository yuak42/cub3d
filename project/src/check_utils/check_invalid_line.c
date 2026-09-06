/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:14:50 by yuak              #+#    #+#             */
/*   Updated: 2026/09/06 19:59:00 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_invalid(char *line);

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
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

static int	is_invalid(char *line)
{
	if (!ft_strncmp("\n", line, 2))
		return (0);
	else if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3))
		return (0);
	else if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		return (0);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
		return (0);
	else if (is_map_line(line))
		return (0);
	return (print_error_arg("Error\nUnidentified line: ?\n", line), 1);
}
