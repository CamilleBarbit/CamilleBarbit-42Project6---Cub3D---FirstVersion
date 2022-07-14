/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_argv1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:11:43 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/14 19:12:29 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
* @param str
	str is my argv1 (the file with the extension .cub)
* * The function checks the validity of argv1
	1) It checks that the len is higher than 4 -> it cannot be .cub (it is a hidden file)
**/

int	check_validity_argv1(const char *str)
{
	if (ft_strlen(str) < 4)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}