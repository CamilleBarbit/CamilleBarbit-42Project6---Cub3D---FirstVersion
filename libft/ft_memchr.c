/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:40:36 by cbarbit           #+#    #+#             */
/*   Updated: 2021/11/30 14:59:58 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sub;
	size_t			i;

	sub = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sub[i] == (unsigned char)c)
			return ((unsigned char *)&sub[i]);
		i++;
	}
	return (NULL);
}
