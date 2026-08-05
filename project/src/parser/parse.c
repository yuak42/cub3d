/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/06/27 22:29:25 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*parse(int ac, char **ar)
{
	int fd;
	char *line;

	if (ac != 2)
		return (NULL);
	fd = open(ar[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		line = get_next_line(fd);
	}
	return (NULL);
}