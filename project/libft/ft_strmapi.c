/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:20:58 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:24 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*temp;
	unsigned int	size;

	if (f == NULL)
		return (NULL);
	temp = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
