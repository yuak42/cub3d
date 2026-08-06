/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:07:56 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:09 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		head = (*temp).next;
		ft_lstdelone(temp, del);
		temp = head;
	}
	*lst = NULL;
}
