/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_argv1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:11:43 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/14 16:46:13 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
* @param str 
    str is my argv1 (the file with the extension .cub)
* @param check
    check is my structure with key values that I need to keep during my parsing
* * The function counts the number of dots it encounters in the string
* ! There cannot be more that one dot! If count != 1, then it is wrong
**/

static int	count_dots(const char *str, t_parsing *check)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			check->index = i;
			count++;
		}
		i++;
	}
	return (count);
}


/**
* @param str
    str is my argv1 (the file with the extension .cub)
* @param check
    check is my structure with key values that I need to keep during my parsing
* * The function checks the validity of argv1
    1) It checks that there is just one dot in the string
    2) 
**/

int	check_validity_argv1(const char *str, t_parsing *check)
{
	if (count_dots(str, check) != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}