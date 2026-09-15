/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:59:12 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:03:47 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_NEXT_LINE_H
# define READ_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		read_next_line(int fd, char **line);

int		return_fail(char **buffer);
int		handle_eof(char **line);
void	rnl_copy_str(char *dest, char *src);
int		handle_wrong_arg(char **line, char **buffer);

int		implement_buffer(char **buffer);
void	rnl_shift_buffer(char *buffer);
int		rnl_connect_buffer(char *buffer, char **line);
int		handle_buffer_new_line(char **line, char *buffer);

int		rnl_is_new_line(char *line);
char	*extract_line(char *line);
int		handle_new_line(char **line);

#endif