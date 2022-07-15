/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:23:10 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/15 19:42:44 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
*	@param str 
    	str is my argv1 (the file with the extension .cub)
	@param argc
		argc is the total number of arguments my program has
*	*The function checks the basic validity of my program when it launches
		1) It checks the total number of arguments
*			!If argc != 2 -> it is wrong
		2) It checks the syntax of argv(1)
**/

static int	parsing_argv1(int argc, const char *str)
{
	if (argc != 2)
	{
		ft_error("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (check_validity_argv1(str) == 1 || file_exists(str) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	*map_infos;

	map_infos = malloc(sizeof(t_info));
	if (!map_infos)
		return (EXIT_FAILURE);
	if (parsing_argv1(argc, argv[1]) == 1)
		return (free(map_infos), EXIT_FAILURE);
	free(map_infos); //in case of success, need to free all that has been allocated
	return (EXIT_SUCCESS);	
}