/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:08:44 by yuak              #+#    #+#             */
/*   Updated: 2026/09/06 20:13:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_next_line.h"

static int	read_file(int fd, char **line, char *buffer);

int	read_next_line(int fd, char **line)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (handle_wrong_arg(line, &buffer));
	if (implement_buffer(&buffer))
		return (*line = NULL, buffer = NULL, 1);
	if (rnl_is_new_line(buffer))
		return (handle_buffer_new_line(line, buffer));
	*line = ft_strdup("");
	if (!(*line))
		return (*line = NULL, return_fail(&buffer));
	if (rnl_connect_buffer(buffer, line))
		return (free(*line), *line = NULL, return_fail(&buffer));
	rnl_shift_buffer(buffer);
	if (read_file(fd, line, buffer))
		return (return_fail(&buffer));
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	else
		rnl_shift_buffer(buffer);
	return (0);
}

static int	read_file(int fd, char **line, char *buffer)
{
	ssize_t	i;
	
	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(*line), *line = NULL, 1);
		buffer[i] = '\0';
		if (i == 0)
			return (handle_eof(line));
		if (rnl_connect_buffer(buffer, line))
			return (free(*line), *line = NULL, 1);
		if (rnl_is_new_line(*line))
			return (handle_new_line(line));
	}
	return (0);	
}

