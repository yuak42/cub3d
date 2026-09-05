/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:11:01 by yuak              #+#    #+#             */
/*   Updated: 2026/09/05 13:50:37 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shift_buffer(char *buffer);
char	*extract_line(char *line);
int		mplement_buffer(char **buffer);

int	implement_buffer(char **buffer)
{
	if ((*buffer))
		return (0);
	*buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*buffer))
		return (1);
	(*buffer)[BUFFER_SIZE] = '\0';
	return (0); 
}

int	return_fail(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (1);
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
	shift_buffer(buffer);
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
