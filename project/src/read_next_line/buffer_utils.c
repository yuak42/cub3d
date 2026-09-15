/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:11:01 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 09:41:39 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_next_line.h"

int	implement_buffer(char **buffer)
{
	if ((*buffer))
		return (0);
	*buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!(*buffer))
		return (1);
	return (0);
}

void	rnl_shift_buffer(char *buffer)
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

int	rnl_connect_buffer(char *buffer, char **line)
{
	char	*new_line;
	size_t	old_size;
	size_t	buffer_size;

	old_size = ft_strlen(*line);
	buffer_size = ft_strlen(buffer);
	new_line = (char *) ft_calloc(old_size + buffer_size + 1, sizeof(char));
	if (!new_line)
		return (1);
	rnl_copy_str(new_line, *line);
	rnl_copy_str(new_line + old_size, buffer);
	free(*line);
	*line = new_line;
	return (0);
}

int	handle_buffer_new_line(char **line, char *buffer)
{
	*line = extract_line(buffer);
	if (!(*line))
		return (*line = NULL, return_fail(&buffer));
	shift_buffer(buffer);
	return (0);
}
