/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:25:39 by wasman            #+#    #+#             */
/*   Updated: 2016/10/27 12:11:18 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int find_last_one_char(char *bitmap)
{
	int length = ft_strlen(bitmap);
	int i = length;
	while (i && bitmap[i] != '1')
		i--;
//	printf("LAST ONE RETURNS: %d\n", (length - i));
//	return (length - i);
	return i;
}

int find_first_one_char(char *bitmap)
{
	int length = ft_strlen(bitmap);
	int i = 0;
	while (bitmap[i] != '1' && i < length)
		i++;
//	printf("FIRST ONE RETURNS: %lu\n", ft_strlen(bitmap)-i);
//	return (ft_strlen(bitmap) - i);
	return (i);
}

char	*shift(char *tet, int size, int width)
{
	int	max;
	int	len;
	char	*tmp;
	int	i;
	int j;
	int h;

	max = 0;
	len = 0;
	i = 0;
	h = 0;
	j = 1;//the first index of tmp[0] will always be '0' if it is fair shift
	if (tet == NULL)
		return 0;
	while (tet[len] != '\0')
		len++;
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	len--;
	tmp = ft_memset(tmp, '0', len);
	
	if (tet[len] != '1')//if the last char is not a 1 and therefore we can shift without truncating 
	{
		while(tet[i] != '\0')//reads through the entire input string
		{
			if ((find_last_one_char(tet) % size == 0) || ((find_first_one_char(tet)+width)% size == 0) )
			{	//shift by width if (get_last_char(tet) + width) is greater than length
				if (find_last_one_char(tet) != len)
				{
					while (h < width - 1)
					{
						if (i == len)
							return 0;
						tmp[j++]= '0';
	//					i++;
						h++;
					}
				}
			}
			//copy i-1
				tmp[j] = tet[i]; //since j started at 1, we are copying a shifted by one string;
				i++;
				j++;
		}
		tmp[len+1] = 0;
//		printf("THIS IS THE ORIGINAL TET: %s SIZE : %d\n", tet, size);
//		printf("THIS IS THE SHIFTED TET: %s\n", tmp);
		return (tmp);
	}
	return (NULL);
}

//if first 1 is on the edge and width is greater than 1 shift by (width - 1)?
//..AA
//..AA







//needs to shift by 1 except in the case that a tetrimino is on the edge by shifting we're just adding a zero to a newly created string at the index -1
//
//call get_first_char 
//call get_last_char
//
//if (((get first char() + width)) %size = 0 || (get_last_char) % size ==0))
//	if you can shift without cutting off blocks(truncating)
//		shift by width instead of by 1;
//
//The new string needs to have atleast as many characters as the previous string (not any more otherwise shifting won't be accurate)
//
//
