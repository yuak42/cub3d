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

int	init_window(t_win *s_window)
{
	void	*window;

	window = mlx_init();
	if (!window)
	{
		printf("mlx_init error\n");
		return (NULL);
	}
	return (0);
}