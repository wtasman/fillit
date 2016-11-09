/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:30:04 by wasman            #+#    #+#             */
/*   Updated: 2016/11/06 00:31:02 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_sizetwo(char *tet_string, char *offset_string)
{
	if (ft_strcmp(tet_string, "1100110000000000") == 0)
	{
		offset_string[0] = '1';
		offset_string[1] = '1';
		offset_string[2] = '1';
		offset_string[3] = '1';
		offset_string[4] = 0;
		return (offset_string);
	}
	return (NULL);
}

char	*ft_sizethree(char *tet_string, char *offset_string)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (ft_strcmp(tet_string, "1111000000000000") == 0 ||
			ft_strcmp(tet_string, "1000100010001000") == 0)
		return (NULL);
	offset_string = (char *)malloc(sizeof(char) * 10);
	while (tet_string[i] && i < 12)
	{
		if (i != 3 && i != 7)
			offset_string[j++] = tet_string[i];
		i++;
	}
	offset_string[9] = 0;
	return (offset_string);
}

char	*ft_grow(char *offset_string, int j, int size)
{
	int h;

	h = 0;
	while (h < ((size - 4) * size))
	{
		offset_string[j++] = '0';
		h++;
	}
	offset_string[size * size] = 0;
	return (offset_string);
}

char	*ft_bigsize(char *tet_string, char *offset_string, int size)
{
	int h;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 17)
	{
		h = 0;
		if (i != 4 && i != 8 && i != 12 && i != 16 && tet_string[i])
			offset_string[j++] = tet_string[i];
		else
		{
			while (h < (size - 4))
			{
				offset_string[j++] = '0';
				h++;
			}
			if (tet_string[i])
				offset_string[j++] = tet_string[i];
		}
		i++;
	}
	ft_grow(offset_string, j, size);
	return (offset_string);
}

char	*fix_offset(char *tet_string, int size)
{
	char *offset_string;

	offset_string = (char *)malloc(sizeof(char) * (size * size) + 1);
	if (!(*tet_string))
		return (0);
	if (size == 2)
		offset_string = ft_sizetwo(tet_string, offset_string);
	if (size == 3)
		offset_string = ft_sizethree(tet_string, offset_string);
	if (size == 4)
		return (tet_string);
	if (size > 4)
		offset_string = ft_bigsize(tet_string, offset_string, size);
	return (offset_string);
}
