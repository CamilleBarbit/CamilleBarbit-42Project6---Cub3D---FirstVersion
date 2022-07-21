/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_and_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:21:46 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/20 17:24:56 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


static int check_line_description(t_info *parsing, const char *str1)
{
	int     i; //index going through the line in question
	int     j; //index starting from the first character which is not a space
	int		k;
	//char    *str2; //it is each line that is not empty

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
			//aller modif le tableau booléen tab
		}
		i++;
	}
}


/**
 *	@param parsing
 *      parsing contains all the information of the file x.cub in a char **
 *	*This function will look at the texture and color description
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
		if (line_is_empty(parsing->file_infos[i]) == 0)
		{
			nb_lines--;
			if (check_line_description(parsing, parsing->file_infos[i]) == 1)
				return (EXIT_FAILURE);
			if (compare_lines_and_identifiers(parsing) == 1)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
