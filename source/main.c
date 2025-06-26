/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:34:55 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 14:35:53 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*file;
	t_game	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(game));
		if (check_file_name(argv[1]))
		{
			file = reader(argv[1]);
			if (file_checker(file))
			{
				game.data = parser(file);
				if (map_checker(game.data))
					minilibx(&game);
				free_data(game.data);
				free_game(&game);
			}
			free(file);
		}
	}
	else
		error(40, "main.c", \
		"You have to give two correct arguments on terminal", NULL);
	return (0);
}
