/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:04:45 by yuak              #+#    #+#             */
/*   Updated: 2026/09/20 10:12:51 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "check.h"
#include "data.h"

static int	check_texture_path(char *path);

int	check_texture_paths(t_game *game)
{
	if (check_texture_path(game->texture.no))
		return (1);
	if (check_texture_path(game->texture.so))
		return (1);
	if (check_texture_path(game->texture.we))
		return (1);
	if (check_texture_path(game->texture.ea))
		return (1);
	return (0);
}

static int	check_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error_arg("Error\n? does not exits\n", path);
		return (1);
	}
	close(fd);
	return (0);
}
