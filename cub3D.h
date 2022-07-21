/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:23:13 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/20 17:20:25 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*Libraries*/

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include <stdbool.h>

/* Structures */

typedef struct	s_info
{
	// char	**texture;
	// char	**colour;
	// char	**map;
	const char	**file_infos; //all the infos from the file x.cub
	int			size; //size of the file, empty lines included
	bool    	tab[6]; 
	const char	**identifiers; //containing the different combinations of textures
	char	*line;
}	t_info;

/* Errors */
void	ft_error(const char *str);

/* Parsing */
int		check_validity_argv1(const char *str);
int		file_exists(const char *str);
int		check_space_and_place(t_info *parsing);
void	ft_extract_infos(t_info *parsing, const char *str);
void	print_tab(t_info *parsing);
void	print_tab_bis(t_info *parsing);
int		init_infos_textures_colors(t_info *parsing);
int		line_is_empty(const char *str);
int		check_texture_and_color(t_info *parsing);
int		str_compare(char const *s1, char *s2);

#endif