/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:39:28 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/30 12:01:03 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
