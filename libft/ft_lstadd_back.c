/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:12:15 by camillebarb       #+#    #+#             */
/*   Updated: 2021/12/01 12:51:03 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tempo;

	tempo = *alst;
	while (tempo)
	{
		if (tempo->next == NULL)
		{
			tempo->next = new;
			return ;
		}
		tempo = tempo->next;
	}
	*alst = new;
}
