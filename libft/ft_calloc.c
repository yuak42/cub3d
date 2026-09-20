/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:33:52 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:57:56 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			limit;
	unsigned char	*temp;

	limit = (size_t) -1;
	if (size != 0 && nmemb > limit / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, nmemb * size);
	return (temp);
}
