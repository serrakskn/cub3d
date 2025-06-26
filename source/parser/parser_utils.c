/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:19:25 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:12:34 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include "../../library/libft/libft.h"

int	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (!!str && str[i])
		i++;
	return (i);
}

char	*get_data_value(t_data data, char *field)
{
	int	i;

	i = 0;
	while (data.value[i][0])
	{
		if (!ft_strncmp(data.value[i], field, ft_strlen(field)))
			return (ft_strdup(&data.value[i][ft_strlen(field) + 1]));
		i++;
	}
	return (NULL);
}

int	get_longer_line_length(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
