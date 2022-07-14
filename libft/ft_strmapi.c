/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:43:11 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/30 14:53:35 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*sbis;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sbis = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!sbis)
		return (NULL);
	while (s[i] && i < ft_strlen(s))
	{
		sbis[i] = f(i, s[i]);
		i++;
	}
	sbis[i] = '\0';
	return (sbis);
}
