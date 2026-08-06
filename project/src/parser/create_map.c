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

t_map *create_map(char *cub)
{
	t_map	*map;

	map = init_map(cub);
	if (!map)
		return (NULL);
	if (assign_grid(map, cub) < 0)
		return (NULL);
	ft_printf("Map was extracted successfully\n");
	ft_printf("Map width: %d, map height: %d\n", map->width, map->height);
	print_grid(map->grid);

	return (map);
}
