/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_starting_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:22:29 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 09:37:03 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_starting_position_number(char *line);
static int	is_starting_position_char(char c);
static int	get_return(int num);

int	check_starting_position(char *cub)
{
	char	*line;
	int		num;
	int		fd;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), 1);
	num = 0;
	while (line)
	{
		if (is_map_line(line))
			num += get_starting_position_number(line);
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), close(fd), 1);
	}
	return (close(fd), read_next_line(-1, NULL), get_return(num));
}

static int	get_starting_position_number(char *line)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (line[i])
	{
		if (is_starting_position_char(line[i]))
			num++;
		i++;
	}
	return (num);
}

static int	is_starting_position_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	get_return(int num)
{
	if (num == 1)
		return (0);
	if (num == 0)
		print_error("Error\nThere is no starting position on map\n");
	else if (num > 1)
		print_error("Error\nThere are more than 1 starting position on map\n");
	return (1);
}
