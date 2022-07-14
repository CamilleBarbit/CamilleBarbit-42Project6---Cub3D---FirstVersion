/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:23:10 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/14 19:02:19 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (check_validity_argv1(argv[1]) == 1)
	{
		ft_error("Invalid argument\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);	
}