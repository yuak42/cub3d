/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:06:55 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	(*head).content = content;
	(*head).next = NULL;
	return (head);
}
