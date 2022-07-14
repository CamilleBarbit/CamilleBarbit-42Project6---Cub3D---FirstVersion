/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:39 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/14 19:20:45 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
* @param
	str is the error message to print
* *Function printing error message
**/

void	ft_error(const char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
}
