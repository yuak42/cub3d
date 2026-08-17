/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:14:50 by yuak              #+#    #+#             */
/*   Updated: 2026/08/17 11:55:55 by yuak             ###   ########.fr       */
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
			return (close(fd), free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	is_invalid(char *line)
{
	static int	l;

	l++;
	if (!ft_strncmp("\n", line, 2))
		return (0);
	else if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3))
		return (0);
	else if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
		return (0);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("C ", line, 2))
		return (0);
	else if (check_map_line(line))
		return (ft_printf("Error\nUnidentified line %d: %s", l - 1, line), 1);
	return (ft_printf("undetected error\n"), 1);
}

static int	check_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			i++;
			continue;
		}
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N')
		{
			i++;
			continue;
		}
		if (line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			i++;
			continue;
		}
		return (1);
	}
	return (0);
}
