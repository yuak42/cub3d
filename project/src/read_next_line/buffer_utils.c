/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:11:01 by yuak              #+#    #+#             */
/*   Updated: 2026/09/06 18:36:40 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	implement_buffer(char **buffer)
{
	if ((*buffer))
		return (0);
	*buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!(*buffer))
		return (1);
	return (0); 
}

void	shift_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			while (buffer[i])
			{
				buffer[j] = buffer[i + 1];
				i++;
				j++;
			}
			break ;
		}
		i++;
	}
	while (buffer[j])
	{
		buffer[j] = '\0';
		j++;
	}
}

int	connect_buffer(char *buffer, char **line)
{
	char	*new_line;
	size_t	old_size;

	old_size = ft_strlen(*line);
	new_line = (char *) ft_calloc(old_size + BUFFER_SIZE + 1, sizeof(char));
	if (!new_line)
		return (1);
	ft_strcpy(new_line, *line);
	ft_strcpy(new_line + old_size, buffer);
	free(*line);
	*line = new_line;
	return (0);
}
