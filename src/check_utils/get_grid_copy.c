/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:05:42 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:48:32 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "check.h"
#include "libft.h"

static void	free_backwards(char **copy, int i);

char	**get_grid_copy(char **grid)
{
	char	**copy;
	int		i;

	copy = (char **) ft_calloc((get_splitted_size(grid) + 1), sizeof(char **));
	if (!copy)
		return (perror("Error"), NULL);
	i = 0;
	while (*grid)
	{
		copy[i] = ft_strdup(*grid);
		if (!copy[i])
			return (free_backwards(copy, i - 1), NULL);
		i++;
		grid++;
	}
	return (copy);
}

static void	free_backwards(char **copy, int i)
{
	while (i >= 0)
	{
		free(copy[i]);
		i--;
	}
	free(copy);
}
