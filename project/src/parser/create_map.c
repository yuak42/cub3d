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
// Update header

#include "cub3d.h"

char **create_map(char **av)
{
	char	**map;
	size_t	size;

	size = get_map_size(av);
	if (size == 0)
		return (ft_printf("Error\n"), NULL);
	map = (char **) ft_calloc(size, sizeof(char *));
	if (!map)
		return (perror("Error"), NULL);


	return (NULL);
}

