/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:40:26 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:11:28 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include "../../library/libft/libft.h"

static void	restore_map(t_data *data, char perspective)
{
	int	i;
	int	q;

	i = 0;
	while (data->map[i])
	{
		q = 0;
		while (data->map[i][q])
		{
			if (data->map[i][q] == CONTROL)
				data->map[i][q] = ROAD;
			q++;
		}
		i++;
	}
	data->map[data->player.x][data->player.y] = perspective;
}

int	check_wall(t_data *data, int x, int y)
{
	t_point	size;

	size.y = data->map_height;
	if (is_inside_map(data, x, y) && data->map[y][x] != CONTROL
		&& data->map[y][x] != WALL)
	{
		size.x = ft_strlen(data->map[y]);
		if (data->map[y][x] == SPACE)
			return (error(46, "checker/map_checker.c", \
				"There is space in the map", NULL));
		if (x == 0 || y == 0 || size.x - 1 == x || size.y - 1 == y)
			return (error(49, "checker/map_checker.c", \
				"The map is not surrounded by walls", NULL));
		data->map[y][x] = CONTROL;
		if (!check_wall(data, x, y + 1)
			|| !check_wall(data, x + 1, y)
			|| !check_wall(data, x, y - 1)
			|| !check_wall(data, x - 1, y))
			return (0);
	}
	return (1);
}

int	check_floor_and_ceiling(t_data data)
{
	int	result;

	result = 0;
	if (data.floor.r >= 0 && data.floor.r <= 255
		&& data.floor.g >= 0 && data.floor.g <= 255
		&& data.floor.b >= 0 && data.floor.b <= 255
		&& data.ceiling.r >= 0 && data.ceiling.r <= 255
		&& data.ceiling.g >= 0 && data.ceiling.g <= 255
		&& data.ceiling.b >= 0 && data.ceiling.b <= 255)
		result = 1;
	else
		error(74, "checker/map_checker.c", "Color codes are not rgb", NULL);
	return (result);
}

int	check_directions(t_data data)
{
	int	result;

	result = 0;
	if (file_exits(data.north)
		&& file_exits(data.south)
		&& file_exits(data.west)
		&& file_exits(data.east))
		result = 1;
	else
		error(89, "checker/map_checker.c", "Texture file not found", NULL);
	return (result);
}

int	map_checker(t_data data)
{
	char	perspective;
	int		is_check;

	if (!(data.map && data.value
			&& data.north && data.south
			&& data.east && data.west))
		return (0);
	perspective = data.map[data.player.x][data.player.y];
	is_check = check_directions(data);
	if (is_check)
		is_check = check_floor_and_ceiling(data);
	if (is_check)
		is_check = check_wall(&data, data.player.y, data.player.x);
	if (is_check)
		restore_map(&data, perspective);
	return (is_check);
}
