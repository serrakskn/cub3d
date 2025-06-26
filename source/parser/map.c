/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:02:30 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:12:24 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include "../../library/libft/libft.h"

t_point	pass_space(t_data data, t_point point)
{
	while (data.value[point.y][point.x] == SPACE)
		point.x++;
	return (point);
}

t_point	get_map_start_point(t_data data)
{
	int		control;
	t_point	point;
	t_point	start;

	control = 0;
	ft_memset(&point, 0, sizeof(point));
	while (data.value[point.y])
	{
		start.y = point.y;
		start.x = point.x;
		point = pass_space(data, point);
		while (data.value[point.y][point.x] == WALL
				|| data.value[point.y][point.x] == ROAD)
		{
			point.x++;
			control = 1;
		}
		point = pass_space(data, point);
		if (data.value[point.y][point.x] == '\0' && control)
			return (start);
		point.y++;
	}
	start.x = -1;
	start.y = -1;
	return (start);
}

t_data	set_player_point(t_data data)
{
	t_point	point;

	ft_memset(&point, 0, sizeof(point));
	while (data.map[point.x])
	{
		point.y = 0;
		while (data.map[point.x][point.y])
		{
			if (data.map[point.x][point.y] == CHAR_NORTH
			|| data.map[point.x][point.y] == CHAR_SOUTH
			|| data.map[point.x][point.y] == CHAR_EAST
			|| data.map[point.x][point.y] == CHAR_WEST)
				data.player = point;
			point.y++;
		}
		point.x++;
	}
	data.map_height = point.x;
	return (data);
}

char	*create_map_line(t_data data, char *line)
{
	int		length;
	int		most_longer;
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup(" ");
	if (!result)
		return (error(85, "parser/map.c", \
		"Memory allocation failed", NULL), NULL);
	result = ft_strjoin(result, line);
	if (!result)
		return (error(89, "parser/map.c", \
			"Memory allocation failed", NULL), NULL);
	most_longer = get_longer_line_length(data.value);
	length = ft_strlen(line);
	while (i < (most_longer - length) + 1)
	{
		result = ft_strjoin(result, " ");
		if (!result)
			return (error(97, "parser/map.c", \
					"Memory allocation failed", NULL), NULL);
		i++;
	}
	return (result);
}

t_data	set_map_value(t_point start, t_data data)
{
	int		map_size;
	int		i;

	i = 0;
	map_size = 0;
	while (data.value[start.y + map_size])
		map_size++;
	data.map = (char **)malloc(sizeof(char *) * (map_size + 3));
	if (!data.map)
		return (data.map = NULL, data);
	data.map[i] = create_map_line(data, "");
	if (!data.map[i++])
		return (data.map = NULL, data);
	while (data.value[start.y])
	{
		data.map[i] = create_map_line(data, data.value[start.y++]);
		if (!data.map[i++])
			return (data.map = NULL, data);
	}
	data.map[i] = create_map_line(data, "");
	if (!data.map[i])
		return (data.map = NULL, data);
	data.map[i + 1] = NULL;
	return (data);
}
