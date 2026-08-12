/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:37:38 by yuak              #+#    #+#             */
/*   Updated: 2026/08/12 16:34:11 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;
	(void) ac;
	if (check_input(ac, av))
		return (1); 
	game = init_game(av[1]);
	if (!game)
		return (1);
	else
		ft_printf("Game was parsed successfully\n");
	render(game);
	// free everyting
	return (0);
}
