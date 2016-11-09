/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_shifts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:35:32 by wasman            #+#    #+#             */
/*   Updated: 2016/11/06 01:44:08 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**generate_shifts(char *tet_array, int size, int width)
{
	int		length;
	char	**potential_solutions;
	int		i;

	length = ft_strlen(tet_array);
	potential_solutions = (char **)malloc(sizeof(char *) * (length + 1));
	i = 0;
	while (i < length)
	{
		potential_solutions[i++] = (char *)malloc(sizeof(char) * (length + 2));
	}
	i = 1;
	ft_strcpy(potential_solutions[0], tet_array);
	while (shift(potential_solutions[i - 1], size, width) && i < length)
	{
		potential_solutions[i] = shift(potential_solutions[i - 1], size, width);
		i++;
	}
	potential_solutions[i] = 0;
	return (potential_solutions);
}
