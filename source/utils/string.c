/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:44:57 by sekeskin          #+#    #+#             */
/*   Updated: 2024/11/20 17:13:09 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_char_in_string(char *str, char c)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
			result++;
		i++;
	}
	return (result);
}
