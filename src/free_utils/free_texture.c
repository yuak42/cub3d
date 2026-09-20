/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:53:47 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:49:47 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "data.h"

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
