/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:05:08 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/15 19:42:39 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
 *	@param str
 *		 str is the line I am currently reading in the file "x.cub"
 *	*This function will check if the line I am reading is a line from the map description
 * 
 **/

static int	map_beginning(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E' && str[i] != ' ')
			return (2); //it is not part of the map description
		return (3); //it is part of the map description
	}
}

/**
 *	@param str
 *		str is my argv1 (the file with the extension .cub) 
 *	*This function will calculate the total number of (not empty) lines the file x.cub contains
 *		?Before doing that (and before copying each element), we need to verify that in the description of the map, there is not empty line
 * 
 * 
 **/

int	number_of_line_in_file(char *str)
{
	int		fd;
	int		nb_lines;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	nb_lines = 0;
	line = get_next_line(fd);
}	

/**
 *	@param str
 *		str is my argv1 (the file with the extension .cub) 
 *	*This function check the map description
		1) It checks that there is not empty line in the middle of the map description
		2) It checks that there is nothing after the map description
 *	!In no way it means that the map is valid (there must also be the textures and colours)
 * 	!If the line's characters do not correspond to the characters valid in the map description, it means that there is a problem with the map syntax
 * 
 **/

int	check_space_and_place(char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while(line)
	{
		if (map_beginning(line) == 3)
		{
			free(line);
			line = get_next_line(fd);
			while (line && map_beginning(line) == 3)
			{	
				free(line);
				line = get_next_line(fd);
				if (line == NULL)
					break;
			}
			if (map_beginning(line) == 2)
			{
				if (line == '\n')
				{
					free(line);
					line = get_next_line(fd);
					while (line && line == '\n')
					{
						free(line);
						line = get_next_line(fd);
						if (line == NULL)
							break;
					}
					if (map_beginning(line) == 3)
						ft_error("Invalid map: Empty line detected in the map description!\n");
					else
						ft_error("Invalid map: The map description is not the last element of the file!\n");
					return (free(line), EXIT_FAILURE);				
					}
				}
				else
					break;			
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (EXIT_SUCCESS); //there can be a syntax error
}