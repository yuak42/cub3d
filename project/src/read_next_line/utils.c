/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:56:19 by yuak              #+#    #+#             */
/*   Updated: 2026/09/06 20:13:06 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_next_line.h"

int	return_fail(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (1);
}

void rnl_copy_str(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
}

int	handle_eof(char **line)
{
	if ((*line)[0] == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (0);
}

int	handle_wrong_arg(char **line, char **buffer)
{
	if (line)
		*line = NULL;
	return (return_fail(buffer));
}