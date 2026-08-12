/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:31:20 by yuak              #+#    #+#             */
/*   Updated: 2026/08/12 14:49:16 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_texture_paths(char *cub)
{
	if (check_existence_and_uniqueness("NO", cub))
		return (print_error("Error\nNO identifier is wrong!\n"));
	if (check_existence_and_uniqueness("SO", cub))
		return (print_error("Error\nSO identifier is wrong!\n"));
	if (check_existence_and_uniqueness("WE", cub))
		return (print_error("Error\nWE identifier is wrong!\n"));
	if (check_existence_and_uniqueness("EA", cub))
		return (print_error("Error\nEA identifier is wrong!\n"));
	return (0);
}

int check_existence_and_uniqueness(char *id, char *cub)
{
	int		fd;
	char	*line;
	int		exists;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), -1);
	line = get_next_line(fd);
	exists = 0;
	while (!line)
	{
		if (check_line(id, line, &exists))
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int check_line(char *id, char *line, int *exits)
{
	char	*splitted;

	splitted = ft_split(line, ' ');
	if (!splitted)
		return (perror("Error"), 1);
	if (ft_strncmp(id, splitted[0], ft_strlen(id) + 1))
		(*exists)++;
	if (exists > 1)
		return (free_split(splitted), 1);	
	free_split(splitted);

	return (0);
}

void free_split(char **splitted)
{
	char	**temp;
	
	temp = splitted;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(splitted);
}