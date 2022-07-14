/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_argv1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:11:43 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/14 19:42:43 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
* @param str 
    str is my argv1 (the file with the extension .cub)
* * The function counts the number of dots it encounters in the string
* ! There cannot be more that one dot! If count != 1, then it is wrong
**/

static int	count_dots(const char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

/**
* @param str
	str is my argv1 (the file with the extension .cub)
* * The function checks the validity of argv1
	1) It checks that the len is higher than 4 -> it cannot be .cub (it is a hidden file)
**/

int	check_validity_argv1(const char *str)
{
	int	len;
	int	start;

	if (count_dots(str) != 1)
		return (EXIT_FAILURE);
	len = ft_strlen(str);
	start = len - 4;
	if (len < 4)
		return (EXIT_FAILURE);
	if (ft_strncmp(str + start, ".cub", 4) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}