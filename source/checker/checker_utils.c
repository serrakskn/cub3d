/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:09:15 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 15:06:35 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include "../../library/libft/libft.h"

int	is_inside_map(t_data *data, int x, int y)
{
	t_point	size;

	size.y = data->map_height;
	if (x >= 0 && y >= 0 && y < size.y)
	{
		size.x = ft_strlen(data->map[y]);
		if (x < size.x)
			return (1);
	}
	return (0);
}
