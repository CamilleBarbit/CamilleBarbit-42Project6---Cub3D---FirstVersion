/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_and_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:21:46 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/21 13:59:22 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/**
 *	@param parsing
 		parsing contains all the information of the file x.cub in a char **
*	*This function will malloc in a char **parsing->identifiers, a table of strings containing the identifiers for textures and colors
*	*The correct identifiers are the following: "NO"; "SO"; "WE"; "EA"; "F"; "C"
 **/

static int	init_infos_textures_colors(t_info *parsing)
{
	int	i;

	parsing->identifiers = malloc(sizeof(char *) * (6 + 1));
	if (!parsing->identifiers)
		return (EXIT_FAILURE);
	parsing->identifiers[6] = NULL;
	i = 0;
	while (i < 6)
	{
		complete_identifiers(parsing, i);
		i++;
	}
	//print_tab_bis(parsing);
	return (EXIT_SUCCESS);
}

/**
 *	@param parsing
		parsing contains all the information of the file x.cub in a char **
	@param str1
		str1 is a non-empty line (technically corresponding to the texture or color description)
 *	*This function will lextract the first elements contained in str1 that are not spaces
 * 
 **/

static int get_line_description(t_info *parsing, const char *str1)
{
	int     i; //index going through the line in question
	int     j; //index starting from the first character which is not a space
	int		k;

	i = 0;
	j = 0;
	while (str1[i] == ' ')
		i++;
	if (str1[i] != ' ')
	{
		k = i;
		while (str1[i] != ' ')
			i++;
		parsing->line = malloc(sizeof(char *) * ((i - j) + 1));
		if (!parsing->line)
			return (EXIT_FAILURE);
	}
	while (k < i)
	{
		parsing->line[j] = str1[k];
		k++;
		j++;
	}
	parsing->line[j] = '\0';
	//printf("STRING: %s\n", parsing->line);
	return (EXIT_SUCCESS);	
}

static int	compare_lines_and_identifiers(t_info *parsing)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (str_compare(parsing->identifiers[i], parsing->line) == 0)
		{
			parsing->tab[i] = 1;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	ft_error("Invalid texture or color description: Something is wrong with the syntax or just missing!\n");
	return (EXIT_FAILURE);	
}

/**
 *	@param parsing
		parsing contains all the information of the file x.cub in a char **
 *	*This function will look at the texture and color description
		1) It gets the first elements (non spaces) that are in the line
		2) It compares the elements contained in the line with the texture and color identifiers (as reference)
 * 
 **/

int	check_texture_and_color(t_info *parsing)
{
	int i;
	int nb_lines;

	i = 0;
	nb_lines = 6; //nb_lines corresponds to the total number of lines (texture + color descriptions)
	if (init_infos_textures_colors(parsing) == 1)
		return (EXIT_FAILURE);
	while (nb_lines > 0)
	{
		if (!line_is_empty(parsing->file_infos[i]))
		{
			nb_lines--;
			if (get_line_description(parsing, parsing->file_infos[i]) == 1)
				return (EXIT_FAILURE);
			if (compare_lines_and_identifiers(parsing) == 1)
				break;
			free(parsing->line);
		}
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (parsing->tab[i] == 0)
		{
			printf("There is something missing in the description : %s", parsing->identifiers[i]);
			return (EXIT_FAILURE);	
		}
		
		i++;
	}
	return (EXIT_SUCCESS);
}
