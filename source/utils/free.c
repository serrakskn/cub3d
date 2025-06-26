/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:41:30 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 16:55:18 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include <stdlib.h>

void	free_data(t_data data)
{
	int	i;

	i = 0;
	while (data.value[i])
		free(data.value[i++]);
	if (data.value)
		free(data.value);
	i = 0;
	while (data.map[i])
		free(data.map[i++]);
	if (data.map)
		free(data.map);
	if (data.north)
		free(data.north);
	if (data.south)
		free(data.south);
	if (data.west)
		free(data.west);
	if (data.east)
		free(data.east);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->window)
	{
		i = 0;
		while (game->window[i] && i < WINDOW_HEIGHT)
		{
			free(game->window[i]);
			i++;
		}
		free(game->window);
		game->window = NULL;
	}
	if (game->texture)
	{
		i = 0;
		while (game->texture[i] && i < 4)
		{
			free(game->texture[i]);
			i++;
		}
		free(game->texture);
		game->texture = NULL;
	}
}
