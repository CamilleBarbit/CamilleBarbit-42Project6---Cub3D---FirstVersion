/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:04:57 by cbarbit           #+#    #+#             */
/*   Updated: 2021/11/30 14:44:28 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	sizebis;

	sizebis = size * nmemb;
	ptr = malloc(sizebis);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizebis);
	return (ptr);
}
