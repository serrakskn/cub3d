/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:39:58 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:04:49 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include "../../library/libft/libft.h"

t_data	parse_map(t_data data)
{
	t_point	start;

	start = get_map_start_point(data);
	if (start.x == -1 && start.y == -1)
		return (data.map = NULL, data);
	data = set_map_value(start, data);
	if (!data.map)
		return (data);
	data = set_player_point(data);
	return (data);
}

t_data	parse_floor_and_ceiling(t_data data)
{
	data = parse_floor(data);
	data = parse_ceiling(data);
	return (data);
}

t_data	parse_directions(t_data data)
{
	data.north = ft_strtrim(get_data_value(data, NORTH), " ");
	if (!data.north)
		error(41, "parser/parser.c",
			"Memory allocation failed", NULL);
	data.south = ft_strtrim(get_data_value(data, SOUTH), " ");
	if (!data.north)
		error(45, "parser/parser.c",
			"Memory allocation failed", NULL);
	data.east = ft_strtrim(get_data_value(data, EAST), " ");
	if (!data.north)
		error(49, "parser/parser.c",
			"Memory allocation failed", NULL);
	data.west = ft_strtrim(get_data_value(data, WEST), " ");
	if (!data.north)
		error(53, "parser/parser.c",
			"Memory allocation failed", NULL);
	return (data);
}

t_data	parser(char	*file)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	data.value = ft_split(file, '\n');
	if (!data.value)
		return (error(65, "parser/parser.c",
				"Memory allocation failed", NULL), data);
	data = parse_directions(data);
	data = parse_floor_and_ceiling(data);
	data = parse_map(data);
	return (data);
}
