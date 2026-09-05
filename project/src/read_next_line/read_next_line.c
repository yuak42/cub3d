/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:08:44 by yuak              #+#    #+#             */
/*   Updated: 2026/09/05 13:49:10 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_next_line(int fd, char **line)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (return_fail(buffer));
	if (implement_buffer(&buffer))
		return (1);
	if (is_new_line(buffer))
	{
		*line = extract_new_line(buffer);
		if (!(*line))
			return (return_fail(buffer));
		return (0);
	}
	*line = NULL;
	if (connect_buffer(line, buffer))
		return (return_fail(buffer));
	if (read_file(fd, line, buffer))
		return (return_fail(buffer));
	return (0);
}
