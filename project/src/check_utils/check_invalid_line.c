/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:14:50 by yuak              #+#    #+#             */
/*   Updated: 2026/09/06 20:03:00 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_invalid(char *line);

int	check_invalid_line(char *cub)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	status = read_next_line(fd, &line);
	if (status != 0)
		return (close(fd), perror("Error"), 1);
	while (line)
	{
		if (is_invalid(line))
			return (free(line), close(fd), read_next_line(-1, NULL));
		free(line);
		status = read_next_line(fd, &line);
		if (status != 0)
			return (close(fd), perror("Error"), 1);
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
