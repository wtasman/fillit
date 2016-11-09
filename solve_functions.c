/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:01:52 by whickey           #+#    #+#             */
/*   Updated: 2016/11/06 01:01:10 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fit_char(char *bitmap_str, char **square_str, int size)
{
	int i;
	int flag;
	int len;

	i = 0;
	flag = 0;
	len = ft_strlen(bitmap_str) - 1;
	if (!*bitmap_str)
		return (0);
	while (i < size * size)
	{
		if (bitmap_str[i] == '1' && conflicts(square_str, i))
			return (0);
		i++;
	}
	return (1);
}

char	**fix_all(char **tet_array, int size)
{
	char **offset_tet;
	char **ptr;
	char **original_tet;

	offset_tet = (char **)malloc(sizeof(char *) * 27);
	offset_tet = ft_memset(offset_tet, 0, 27);
	ptr = offset_tet;
	original_tet = tet_array;
	while (!is_empty(*original_tet, size))
	{
		if (!(*offset_tet = fix_offset(*original_tet, size)))
			return (0);
		offset_tet++;
		original_tet++;
	}
	return (offset_tet = ptr);
}

int		num_of_tets(unsigned short *bitmap_array)
{
	int num;

	num = 0;
	while (*bitmap_array++)
		num++;
	return (num);
}

void	clear(char **solution, int size)
{
	int i;

	i = -1;
	while (++i < 26)
		ft_memset(solution[i], '0', size * size);
}

char	**solve(char **tet_array, unsigned short *bit, char **tet_sol)
{
	int		size;
	int		i;
	char	**solution;
	char	**offset_tet;

	i = -1;
	size = 1;
	solution = (char **)malloc(sizeof(char*) * 27);
	solution = ft_memset(solution, 0, 27);
	while (++i < 27)
	{
		solution[i] = (char *)malloc(sizeof(char) * 500);
		solution[i] = ft_memset(solution[i], '0', 500);
	}
	while (++size < 14)
	{
		if ((fix_all(tet_array, size)))
		{
			offset_tet = fix_all(tet_array, size);
			if ((is_fit(offset_tet, bit, tet_sol, size)))
				return (tet_sol);
			clear(tet_sol, size);
		}
	}
	return (0);
}
