/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_argv1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:11:43 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/15 19:42:43 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
*	@param str 
		str is my argv1 (the file with the extension .cub)
*	*The function counts the number of dots it encounters in the string
*		!There cannot be more that one dot! If count != 1, then it is wrong
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
*	@param str
		str is my argv1 (the file with the extension .cub)
*	*The function checks the validity of argv1
		1) It checks that the len is higher than 4
*			!It cannot be ".cub" (it is a hidden file)
		2) It compares the last four characters of the string str with ".cub"
*			!If it defers in any way, then it cannot be valid
**/

int	check_validity_argv1(const char *str)
{
	int	len;
	int	start;
	int	nb_dots;
	
	nb_dots = count_dots(str);
	if (nb_dots != 1)
	{
		if (nb_dots == 0)
			ft_error("Invalid argument: Dot is missing!\n");
		else
			ft_error("Invalid argument: Too many dots!\n");
		return (EXIT_FAILURE);
	}
	len = ft_strlen(str);
	start = len - 4;
	if (ft_strncmp(str + start, ".cub", 4) != 0)
		return (ft_error("Invalid argument: Wrong extension!\n"), EXIT_FAILURE);
	if (len < 5)
		return (ft_error("Invalid argument: Your file is a hidden file!\n"), EXIT_FAILURE);		
	return (EXIT_SUCCESS);
}

/**
*	@param str
		str is my argv1 (the file with the extension .cub)
*	*The function checks, once my .cub is valid, if it exits somewhere and can be opened
**/

int	file_exists(const char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Valid argument but the file could not be opened!\n");
		return (-1);
	}
	return (EXIT_SUCCESS);
}