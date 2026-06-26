/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:37:38 by yuak              #+#    #+#             */
/*   Updated: 2026/06/26 20:01:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	void	*conn_ptr;
	void	*win_ptr;

	conn_ptr = mlx_init();
	if (!conn_ptr)
	{
		printf("Connection with the X server cannot be esthabilished!\n");
		return (1);
	}
	win_ptr = mlx_new_window(conn_ptr, 800, 600, "The First Window");
	if (!win_ptr)
	{
		printf("Window cannot be created!\n");
		return (2);
	}
	mlx_loop(conn_ptr);
	return (0);
}