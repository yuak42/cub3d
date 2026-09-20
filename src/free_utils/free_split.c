/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 08:24:03 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:29:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **splitted)
{
	char	**temp;

	temp = splitted;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(splitted);
}
