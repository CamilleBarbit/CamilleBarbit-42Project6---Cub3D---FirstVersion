/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:42:11 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/29 17:29:14 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *string, int c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == (char)c)
		return ((char *)&string[i]);
	return (NULL);
}
