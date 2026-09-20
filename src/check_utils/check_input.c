/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:23:55 by yuak              #+#    #+#             */
/*   Updated: 2026/09/19 10:10:53 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_input(int ac, char **av)
{
	if (ac != 2)
		return (print_error("Error\nInput number wrong!\n"), 700);
	if (check_file_format(av[1]))
		return (print_error("Error\nFile format is wrong!\n"), 700);
	if (check_invalid_line(av[1]))
		return (1);
	if (check_identifiers(av[1]))
		return (1);
	if (check_colors(av[1]))
		return (1);
	if (!is_there_map(av[1]))
		return (1);
	if (!is_map_position_true(av[1]))
		return (1);
	if (check_starting_position(av[1]))
		return (1);
	return (0);
}
