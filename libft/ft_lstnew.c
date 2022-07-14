/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:42:18 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/29 13:28:15 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*maillon;

	maillon = malloc(sizeof(t_list));
	if (!maillon)
		return (NULL);
	maillon->next = NULL;
	maillon->content = content;
	return (maillon);
}
