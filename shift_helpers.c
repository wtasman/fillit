/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:47:33 by whickey           #+#    #+#             */
/*   Updated: 2016/11/07 23:47:35 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_last_one_char(char *bitmap)
{
	int length;
	int i;

	length = ft_strlen(bitmap);
	i = length;
	while (i && bitmap[i] != '1')
		i--;
	return (i);
}

int		find_first_one_char(char *bitmap)
{
	int length;
	int i;

	length = ft_strlen(bitmap);
	i = 0;
	while (bitmap[i] != '1' && i < length)
		i++;
	return (i);
}
