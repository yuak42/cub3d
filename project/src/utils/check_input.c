/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:23:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/08 21:11:55 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_input(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (check_file(av[1]))
		return (2);

	return (0);
}

int check_file(char *cub)
{
	if (check_textures(char *cub))
		return (1);
	if (check_map(char *cub))
		return (1);



	return (0);
}

int check_textures(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1);
	line = get_next_line(fd);
	while (line)
	{

		free(line);
		line = get_next_line(line);
	}
		
	return (0);
}

int check_map(char *cub)
{
	int	fd;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1);
	
	close(fd);	

	return (0);
}