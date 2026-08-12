/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:23:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/12 16:34:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_input(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf("Error\nInput number wrong!\n"), 1);
	if (check_texture_paths(av[1]))
		return (2);
	return (0);
}
