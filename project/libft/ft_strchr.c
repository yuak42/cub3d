/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:44:06 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:19 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	unsigned char	*temp;

	temp = (unsigned char *) s;
	uc = (unsigned char) c;
	while (*temp != uc)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return ((char *) temp);
}
