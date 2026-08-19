/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:37:38 by yuak              #+#    #+#             */
/*   Updated: 2026/08/19 10:12:07 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_result(t_game *game);

int	main(int ac, char **av)
{
	t_game	*game;
	(void) ac;
	if (check_input(ac, av))
		return (1); 
	game = init_game(av[1]);
	if (!game)
		return (1);
	if (check_map(game))
		return (free_game(game), 1);
	print_result(game);
	render(game);
	free_game(game);
	return (0);
}

static void print_result(t_game *game)
{
	ft_printf("Game was parsed successfully\n");
	print_map(game->map);
	print_texture_paths(game);
	print_player_info(game);
}


