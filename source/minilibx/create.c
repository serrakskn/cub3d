/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:07:59 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 16:53:41 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include <stdlib.h>

int	create_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->window = (int **)malloc(WINDOW_HEIGHT * sizeof(int *));
	if (!(game->window))
		return (error(24, "minilibx/create.c", \
			"Failed to allocate memory on the heap for game->window", NULL));
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		game->window[i] = (int *)malloc(WINDOW_WIDTH * sizeof(int));
		if (!(game->window[i]))
			return (error(31, "minilibx/create.c", \
				"Failed to allocate memory on the heap for game->window", \
				NULL));
		while (j < WINDOW_WIDTH)
		{
			game->window[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	create_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->texture = (int **)malloc(sizeof(int *) * 4);
	if (!(game->texture))
		return (error(52, "minilibx/create.c", \
			"Failed to allocate memory on the heap for game->texture", NULL));
	while (i < 4)
	{
		j = 0;
		game->texture[i] = (int *)malloc(sizeof(int) * \
		(TEXTURE_HEIGHT * TEXTURE_WIDTH));
		if (!(game->texture[i]))
			return (error(60, "minilibx/create.c", \
				"Failed to allocate memory on the heap for game->texture", \
				NULL));
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}
