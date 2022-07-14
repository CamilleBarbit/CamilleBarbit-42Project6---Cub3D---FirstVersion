/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:43:33 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/30 11:39:46 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *large, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (small[i] == '\0')
		return ((char *)large);
	while (large[i] && i < len)
	{
		j = 0;
		while (small[j] == large[i + j] && i + j < len)
		{
			if (small[j + 1] == '\0')
				return ((char *)&large[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
