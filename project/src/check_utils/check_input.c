/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:23:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/20 14:22:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_input(int ac, char **av)
{
	if (ac != 2)
		return (print_error("Error\nInput number wrong!\n"), 700);
	if (check_texture_paths(av[1]))
		return (1);
	if (check_colors(av[1]))
		return (1);
	if (check_invalid_line(av[1]))
		return (1);
	// check is map exists?
	if (!is_map_position_true(av[1]))
		return (print_error("Error\nMap position is wrong!"), 1);
	if (is_there_unique_start_position(av[1]))
		return (1);
	return (0);
}

