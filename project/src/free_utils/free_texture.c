/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:53:47 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 16:08:08 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_texture texture)
{
	if (texture.no)
		free(texture.no);
	if (texture.so)
		free(texture.so);
	if (texture.we)
		free(texture.we);
	if (texture.ea)
		free(texture.ea);
}