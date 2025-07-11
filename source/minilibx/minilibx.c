/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:40:56 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/24 17:54:32 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../library/cub3d.h"
#include "../../library/minilibx/mlx.h"
#include <unistd.h>

static void	load_game(t_game *game)
{
	game->render.window = mlx_new_window(game->render.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "https://nazlianapa.com.tr");
	game->img.img = mlx_new_image(game->render.mlx, WINDOW_WIDTH \
	, WINDOW_HEIGHT);
	if (!game->img.img)
		error(24, "minilibx/minilibx.c",
			"An error was encountered while creating a new image", NULL);
	else
	{
		game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
				&game->img.size_l, &game->img.endian);
		if (game->img.data)
		{
			mlx_loop_hook(game->render.mlx, &game_render, game);
			mlx_hook(game->render.window, X_EVENT_KEY_PRESS, \
				0, &key_press, game);
			mlx_hook(game->render.window, 17, 42, &close_window, game);
			mlx_hook(game->render.window, X_EVENT_KEY_RELEASE, \
				0, &key_release, game);
			mlx_loop(game->render.mlx);
		}
		else
			error(41, "minilibx/minilibx.c", "Data address retrieval issue", \
				NULL);
	}
}

void	minilibx(t_game *game)
{
	game->render.mlx = mlx_init();
	if (!game->render.mlx)
		return ;
	initialize_fov(game);
	create_window(game);
	create_texture(game);
	if (load_texture(game))
		load_game(game);
}
