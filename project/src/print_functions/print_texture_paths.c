/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 09:06:22 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 09:06:31 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_texture_paths(t_game *game)
{
	ft_printf("\n\nTexture paths:\n");
	ft_printf("NO -> %s\n", game->texture.no);
	ft_printf("SO -> %s\n", game->texture.so);
	ft_printf("WE -> %s\n", game->texture.we);
	ft_printf("EA -> %s\n", game->texture.ea);
	
	ft_printf("F -> r: %d, g: %d, b: %d\n", game->texture.f.r, game->texture.f.g, game->texture.f.b);
	
	ft_printf("C -> r: %d, g: %d, b: %d\n", game->texture.c.r, game->texture.c.g, game->texture.c.b);
}
