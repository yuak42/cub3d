/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:39:52 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parser.h"

t_map	*extract_map(char *cub)
{
	t_map	*map;

	map = init_map(cub);
	if (!map)
		return (NULL);
	if (assign_grid(map, cub))
		return (NULL);
	return (map);
}
