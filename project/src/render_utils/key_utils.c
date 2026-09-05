/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-05 15:45:12 by byaprak           #+#    #+#             */
/*   Updated: 2026-09-05 15:45:12 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int key_code, void *args)
{
	t_render	*ag;

	ag = args;
	ag->key_code = key_code;
	ag->flag = 1;
	return (0);
}

int key_release(int key_code, void *args)
{
	t_render	*ag;

	ag = args;
	ag->key_code = key_code;
	ag->flag = 0;
	return (0);
}