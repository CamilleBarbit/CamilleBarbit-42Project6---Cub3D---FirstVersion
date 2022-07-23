/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:05:08 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/23 20:49:58 by camillebarb      ###   ########.fr       */
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
	if (line_is_empty(str))
		return (2);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E' && str[i] != ' ')
			return (2); //the line is not part of the map description
		i++;
	}
	return (3); //the line is part of the map description
}

/**
 *	@param str
 *		str is my argv1 (the file with the extension x.cub) 
 *	*This function will calculate the total number of lines (empty lines included) in the file x.cub
 **/

static int	map_size(t_info *parsing, const char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_error("The file could not be opened!\n");
		return (1);
	}
	parsing->size = 0;
	line = get_next_line(fd);
	while (line)
	{
		parsing->size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (parsing->size < 6)
	{
		ft_error("There are not enough lines in the file!\n");
		return (1);	
	}
	return (0);
}

/**
 *	@param parsing
 *		parsing contains all the information of the file x.cub in a char **
 *	@param str
		str is my argv1 (the file with the extension .cub)
*	*This function will malloc in a char **parsing->file_infos containing everything that is in the file
 **/

int	ft_extract_infos(t_info *parsing, const char *str)
{
	int	fd;
	int	nb_lines;
	int	i;
	int	empty;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_error("The file could not be opened!\n");
		return (1);
	}
	if (map_size(parsing, str) == 1)
		return (1);
	nb_lines = parsing->size;
	i = 0;
	parsing->file_infos = malloc(sizeof(char *) * (nb_lines + 1));
	if (!parsing->file_infos)
		return (1);
	while (nb_lines > 0)
	{
		parsing->file_infos[i] = get_next_line(fd);
		i++;
		nb_lines--;
	}
	parsing->file_infos[i] = '\0';
	nb_lines = parsing->size;
	i = 0;
	while (i < nb_lines)
	{
		if (!line_is_empty(parsing->file_infos[i]))
		{
			empty = 1;
			break;
		}
		empty = 0;
		i++;
	}
	close(fd);
	if (empty == 0)
	{
		ft_error("The file is empty!\n");
		return (1);
	}
	return (0);
}

/**
 *	@param str
 *		str is my argv1 (the file with the extension .cub) 
 *	*This function check the map description
		1) It checks that there is not empty line in the middle of the map description
		2) It checks that there is nothing after the map description
 *	!In no way it means that the map is valid (there must also be the textures and colours)
 * 	!If the line's characters do not correspond to the characters valid in the map description, it means that there is a problem with the map syntax
 **/

int	check_space_and_place(t_info *parsing)
{
	int	i;

	i = 0;
	while (i < parsing->size)
	{
		if (map_beginning(parsing->file_infos[i]) == 3)
		{
			i++;
			while (map_beginning(parsing->file_infos[i]) == 3)
			{
				i++;
				if (i == parsing->size - 1)
					break;
			}
			if (map_beginning(parsing->file_infos[i]) == 2)
			{			
				if (line_is_empty(parsing->file_infos[i]))
				{
					while (line_is_empty(parsing->file_infos[i]))
					{
						i++;
						if (i == parsing->size - 1 && line_is_empty(parsing->file_infos[i]))
							return (EXIT_SUCCESS);							
					}
					if (map_beginning(parsing->file_infos[i]) == 3)
					{
						ft_error("Invalid map: Empty line detected in the map description!\n");
						return (EXIT_FAILURE);	
					}
					else
					{
						ft_error("Invalid map: The map description is not the last element of the file!\n");
						return (EXIT_FAILURE);
					}		
				}		
			}
		}
		i++;
	}
	return (EXIT_SUCCESS); //there can be a syntax error
}
