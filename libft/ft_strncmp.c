/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:43:25 by camillebarb       #+#    #+#             */
/*   Updated: 2021/11/29 18:43:06 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned char	*s1bis;
	unsigned char	*s2bis;
	size_t			i;

	i = 0;
	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1bis[i] && s2bis[i] && s1bis[i] == s2bis[i] && i < n - 1)
		i++;
	return (s1bis[i] - s2bis[i]);
}
