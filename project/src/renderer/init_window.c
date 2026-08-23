/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-23 15:10:20 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-23 15:10:20 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_window(t_win *window)
{
	void	*window;

	window->mlx_ptr = mlx_init();
	window->h = 720;
	window->w = 1280;
	if (!(window->mlx_ptr))
	{
		printf("mlx_init error\n");
		return (0);
	} 
	return (1);
}
