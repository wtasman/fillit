/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:20:12 by whickey           #+#    #+#             */
/*   Updated: 2016/11/08 14:26:36 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**allocate(int x, int y)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char*) * x);
	ret = ft_memset(ret, 0, x);
	while (i < x)
	{
		ret[i] = (char *)malloc(sizeof(char) * y);
		ft_memset(ret[i], '0', y);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int		main(int argc, char **argv)
{
	char			*tet_buffer;
	char			**tet_array;
	char			**solution;
	int				i;
	unsigned short	*bitmap_array;

	if (argc != 2 || !(tet_buffer = readem(argv[1])))
	{
		if (argc != 2)
			ft_putstr("usage: fillit fillit_file\n");
		return (0);
	}
	if (!(bitmap_array = is_valid(tet_buffer)))
	{
		ft_putstr("error\n");
		return (0);
	}
	tet_array = allocate(27, 500);
	solution = allocate(27, 500);
	i = -1;
	while (bitmap_array[++i])
		tet_array[i] = itoa_base(bitmap_array[i], 2);
	tet_array[i] = 0;
	if (tet_array && (solution = solve(tet_array, bitmap_array, ++solution)))
		print_solution(assign_letters(solution));
}
