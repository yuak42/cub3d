/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:37:38 by yuak              #+#    #+#             */
/*   Updated: 2026/09/20 10:07:47 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "free.h"
#include "parser.h"
#include "render.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (check_input(ac, av))
		return (1);
	game = init_game(av[1]);
	if (!game)
		return (2);
	if (check_texture_paths(game))
		return (free_game(game), 3);
	if (check_map(game))
		return (free_game(game), 4);
	if (render(game))
		return (free_game(game), 5);
	free_game(game);
	return (0);
}

