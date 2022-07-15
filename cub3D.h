/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:23:13 by camillebarb       #+#    #+#             */
/*   Updated: 2022/07/15 19:42:46 by camillebarb      ###   ########.fr       */
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

/* Structures */

typedef struct	s_info
{
	char	**texture;
	char	**colour;
	char	**map;
}	t_info;

/* Errors */
void	ft_error(const char *str);

/* Parsing */
int		check_validity_argv1(const char *str);
int		file_exists(const char *str);

#endif