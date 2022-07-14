/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:36 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/29 13:29:21 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	s = (const char *)src;
	d = (char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
		if (d[i] == (char)c)
			return (d + 1);
	}
	return (NULL);
}
