/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:58:17 by yuak              #+#    #+#             */
/*   Updated: 2026/09/05 14:01:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_new_line(char *line)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}

static size_t	get_line_length(char *line);

char	*extract_line(char *line)
{
	size_t	size;
	size_t	i;
	char	*new_line;

	size = get_line_length(line);
	new_line = (char *) malloc((size + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static size_t	get_line_length(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}