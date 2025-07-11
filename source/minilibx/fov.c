/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:11:37 by naanapa           #+#    #+#             */
/*   Updated: 2024/11/20 16:54:03 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"

void	initialize_fov(t_game *game)
{
	game->player.x = game->data.player.x + 0.5;
	game->player.y = game->data.player.y + 0.5;
	if (game->data.map[game->data.player.x][game->data.player.y] == CHAR_NORTH)
	{
		game->direction.x = -1.01;
		game->plane.y = 0.66;
	}
	if (game->data.map[game->data.player.x][game->data.player.y] == CHAR_SOUTH)
	{
		game->direction.x = 1.01;
		game->plane.y = -0.66;
	}
	if (game->data.map[game->data.player.x][game->data.player.y] == CHAR_WEST)
	{
		game->direction.y = -1.01;
		game->plane.x = -0.66;
	}
	if (game->data.map[game->data.player.x][game->data.player.y] == CHAR_EAST)
	{
		game->direction.y = 1.01;
		game->plane.x = 0.66;
	}
	game->move_speed = MOVE_SPEED;
	game->rotation_speed = ROTATION_SPEED;
	game->data.map[game->data.player.x][game->data.player.y] = ROAD;
}
