/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:37:38 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:00:15 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **ar)
{
	(void) ac;
	(void) ar;
	t_game	*game;

	// check_input(ac, ar); 

	game = parse(ac, ar);
	if (!game)
		return (1);
	// if (!game)
	// 	return (1);
	// render(game);
	// free everyting
	return (0);
}