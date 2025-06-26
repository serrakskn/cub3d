/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:42:06 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 11:42:07 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	error(int line, char *file, char *error, char *str)
{
	if (str)
		free(str);
	printf("%s in source/%s on line %d Error\n", error, file, line);
	return (0);
}
