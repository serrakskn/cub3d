/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:02:12 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 16:54:46 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/libft/libft.h"
#include "../../library/cub3d.h"

t_data	parse_floor(t_data data)
{
	char	*text;
	char	**array;
	int		i;
	int		length;

	i = 0;
	text = get_data_value(data, FLOOR);
	data.floor.r = -1;
	if (count_char_in_string(text, ',') == 2)
	{
		array = ft_split(text, ',');
		if (!array)
			return (data);
		length = ft_strlen_2d(array);
		if (length == 3)
		{
			data.floor.r = ft_atoi(array[0]);
			data.floor.g = ft_atoi(array[1]);
			data.floor.b = ft_atoi(array[2]);
		}
		while (length > i)
			free(array[i++]);
		free(array);
	}
	return (free(text), data);
}

t_data	parse_ceiling(t_data data)
{
	char	*text;
	char	**array;
	int		i;
	int		length;

	i = 0;
	text = get_data_value(data, CEILING);
	data.ceiling.r = -1;
	if (count_char_in_string(text, ',') == 2)
	{
		array = ft_split(text, ',');
		if (!array)
			return (data);
		length = ft_strlen_2d(array);
		if (length == 3)
		{
			data.ceiling.r = ft_atoi(array[0]);
			data.ceiling.g = ft_atoi(array[1]);
			data.ceiling.b = ft_atoi(array[2]);
		}
		while (length > i)
			free(array[i++]);
		free(array);
	}
	return (free(text), data);
}
