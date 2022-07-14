/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:40:03 by cbarbit           #+#    #+#             */
/*   Updated: 2021/12/01 13:58:18 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *string, char a)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] != a && (string[i + 1] == a || string[i + 1] == '\0'))
			count += 1;
		i++;
	}
	return (count);
}

static int	ft_count_letters(char const *string, char a)
{
	int	i;

	i = 0;
	while (string[i] && string[i] != a)
		i++;
	return (i);
}

static char	*ft_substr_split(const char *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	while (i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	while (ft_count_words(s, c))
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
			tab[i++] = ft_substr_split(s, 0, ft_count_letters(s, c));
		while (*s && *s != c)
			s++;
	}
	tab[i] = 0;
	return (tab);
}
