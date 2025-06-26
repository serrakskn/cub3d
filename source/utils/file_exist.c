/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:21:49 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:12:40 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	file_exits(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
