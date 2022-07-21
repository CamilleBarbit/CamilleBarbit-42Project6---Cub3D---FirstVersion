/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:23:10 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/20 16:43:24 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
*	@param str 
    	str is my argv1 (the file with the extension x.cub)
	@param argc
		argc is the total number of arguments my program has
*	*The function checks the basic validity of my program when it launches
		1) It checks the total number of arguments
*			!If argc != 2 -> it is wrong
		2) It checks the syntax of argv(1)
		3) It checks two things regarding the map description
			a) That there is no empty line in the middle of the map description
			b) That the map description is the last element in the file x.cub
**/

static int	parsing_argv1(int argc, const char *str, t_info *parsing)
{
	if (argc != 2)
	{
		ft_error("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (check_validity_argv1(str) == 1 || file_exists(str) == -1)
		return (EXIT_FAILURE);
	ft_extract_infos(parsing, str);
	if (check_space_and_place(parsing) == 1)
	 	return (EXIT_FAILURE);
	 if (check_texture_and_color(parsing) == 1)
	  	return (EXIT_FAILURE);		
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	*parsing;

	parsing = malloc(sizeof(t_info));
	if (!parsing)
		return (EXIT_FAILURE);
	if (parsing_argv1(argc, argv[1], parsing) == 1)
		return (free(parsing), EXIT_FAILURE);
	free(parsing); //in case of success, need to free all that has been allocated
	return (EXIT_SUCCESS);	
}