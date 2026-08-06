/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:43:58 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:50:31 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_texture_paths(t_game *game)
{
	ft_printf("\n\nTexture paths:\n");
	ft_printf("NO -> %s\n", game->texture.no);
	ft_printf("SO -> %s\n", game->texture.so);
	ft_printf("WE -> %s\n", game->texture.we);
	ft_printf("EA -> %s\n", game->texture.ea);
	ft_printf("F -> %s\n", game->texture.f);
	ft_printf("C -> %s\n", game->texture.c);
}

int assign_texture(t_game *game, char *line)
{
	char	**splitted;

	line = ft_strtrim(line, "\n"); // error check later
	splitted = ft_split(line, ' ');
	if (!splitted)
		return (perror("Error"), 1);

	if (ft_strnstr(line, "NO ", 3))
		game->texture.no = splitted[1];
	else if (ft_strnstr(line, "SO ", 3))
		game->texture.so = splitted[1];
	else if (ft_strnstr(line, "WE ", 3))
		game->texture.we = splitted[1];
	else if (ft_strnstr(line, "EA ", 3))
		game->texture.ea = splitted[1];
	else if (ft_strnstr(line, "F ", 2))
		game->texture.f = splitted[1];
	else if (ft_strnstr(line, "C ", 2))
		game->texture.c = splitted[1];
	free(splitted[0]);
	free(splitted);
	return (0);
}


int is_texture_line(char *line)
{
	if (ft_strnstr(line, "NO ", 3))
		return (1);
	if (ft_strnstr(line, "SO ", 3))
		return (1);
	if (ft_strnstr(line, "WE ", 3))
		return (1);
	if (ft_strnstr(line, "EA ", 3))
		return (1);
	if (ft_strnstr(line, "F ", 2))
		return (1);
	if (ft_strnstr(line, "C ", 2))
		return (1);
	return (0);
}