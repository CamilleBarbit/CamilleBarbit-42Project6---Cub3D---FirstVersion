/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:36:11 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/20 17:23:14 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	print_tab(t_info *parsing)
{
	int i;

	i = 0;
	while (i < parsing->size)
	{
		printf("%s\n", parsing->file_infos[i]);
		i++;
	}
}

void	print_tab_bis(t_info *parsing)
{
	int i;

	i = 0;
	while (i < 6)
	{
		printf("%s\n", parsing->identifiers[i]);
		i++;
	}
}

int	line_is_empty(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
			return (0); //line is not an empty line
		i++;
	}
	return (1); //line is an empty line
}

static void	complete_identifiers(t_info *parsing, int i)
{
	if (i == 0)
		parsing->identifiers[i] = ft_strdup("NO");
	else if (i == 1)
		parsing->identifiers[i] = ft_strdup("SO");
	else if (i == 2)
		parsing->identifiers[i] = ft_strdup("WE");
	else if (i == 3)
		parsing->identifiers[i] = ft_strdup("EA");
	else if (i == 4)
		parsing->identifiers[i] = ft_strdup("F");
	else if (i == 5)
		parsing->identifiers[i] = ft_strdup("C");
}

int	init_infos_textures_colors(t_info *parsing)
{
	int	i;

	parsing->identifiers = malloc(sizeof(char *) * (6 + 1));
	if (!parsing->identifiers)
		return (EXIT_FAILURE);
	i = 0;
	while (i < 6)
	{
		complete_identifiers(parsing, i);
		i++;
	}
	//print_tab_bis(parsing);
	return (EXIT_SUCCESS);
}


int	str_compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
	{
		ft_error("Invalid texture or color description: Something is wrong with the syntax!\n");
		return (EXIT_FAILURE);		
	}
	while (s1[0] && s2[0] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
	



	while (s1[i] && s2bis[i] && s1bis[i] == s2bis[i] && i < n - 1)
		i++;
	return (s1bis[i] - s2bis[i]);
}