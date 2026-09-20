/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:48:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:25 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (big[i] && i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
