/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:54:50 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 11:58:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp_node;
	t_list	*tail;

	tail = NULL;
	new_lst = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		temp_node = ft_lstnew(f(lst->content));
		if (temp_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (new_lst == NULL)
			new_lst = temp_node;
		else
			tail->next = temp_node;
		tail = temp_node;
		lst = lst->next;
	}
	return (new_lst);
}
