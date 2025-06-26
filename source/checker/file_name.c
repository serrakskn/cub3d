/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:25:35 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:11:18 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/libft/libft.h"
#include "../../library/cub3d.h"

int	check_file_name(char *map)
{
	int	result;

	result = 0;
	if (!ft_strcmp(&map[ft_strlen(map)-4], ".cub"))
		result = 1;
	else
		error(24, "checker/file_name.c", "File type is not supported", NULL);
	return (result);
}
