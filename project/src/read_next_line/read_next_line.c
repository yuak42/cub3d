/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:08:44 by yuak              #+#    #+#             */
/*   Updated: 2026/09/05 14:22:22 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_file(int fd, char *line, char *buffer);

int	read_next_line(int fd, char **line)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (*line = NULL, return_fail(buffer));
	if (implement_buffer(&buffer))
		return (*line = NULL, 1);
	if (is_new_line(buffer))
	{
		*line = extract_line(buffer);
		if (!(*line))
			return (*line = NULL, return_fail(buffer));
		shift_buffer(buffer);
		return (0);
	}
	*line = ft_strdup("");
	if (!(*line))
		return (return_fail(buffer));
	if (connect_buffer(line, buffer))
		return (return_fail(buffer));
	shift_buffer(buffer);
	if (read_file(fd, line, buffer))
		return (return_fail(buffer));
	shift_buffer(buffer);
	return (0);
}

static int	read_file(int fd, char **line, char *buffer)
{
	ssize_t	i;
	char	*new_line;
	
	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(*line), *line = NULL, 1);
		buffer[BUFFER_SIZE] = '\0';
		if (connect_buffer(buffer, line))
			return (free(*line), *line = NULL, 1);
		if (is_new_line(*line))
		{
			new_line = extract_line(*line);
			if (!new_line)
				return (free(*line), *line = NULL, 1);
			free(*line);
			*line = new_line;
			return (0);
		}
	}
	return (0);	
}