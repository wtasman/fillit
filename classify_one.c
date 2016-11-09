/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:32:06 by whickey           #+#    #+#             */
/*   Updated: 2016/11/05 22:37:10 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	is_square(unsigned short tet)
{
	if (!(tet ^ 52224) || !(tet ^ 26112) || !(tet ^ 13056) || !(tet ^ 3264) \
	|| !(tet ^ 1632) || !(tet ^ 816) || !(tet ^ 204) || !(tet ^ 102) \
	|| !(tet ^ 51))
		return (52224);
	else
		return (0);
}

unsigned short	is_vertical_straight(unsigned short tet)
{
	if (!(tet ^ 34952) || !(tet ^ 17476) || !(tet ^ 8738) || !(tet ^ 4369))
		return (34952);
	else
		return (0);
}

unsigned short	is_horizontal_straight(unsigned short tet)
{
	if (!(tet ^ 61440) || !(tet ^ 3840) || !(tet ^ 240) || !(tet ^ 15))
		return (61440);
	else
		return (0);
}

unsigned short	is_normal_t(unsigned short tet)
{
	if (!(tet ^ 58368) || !(tet ^ 29184) || !(tet ^ 3648) || !(tet ^ 1824) \
			|| !(tet ^ 228) || !(tet ^ 114))
		return (58368);
	else
		return (0);
}

unsigned short	is_left_t(unsigned short tet)
{
	if (!(tet ^ 35968) || !(tet ^ 17984) || !(tet ^ 8992) || !(tet ^ 2248) \
			|| !(tet ^ 1124) || !(tet ^ 562))
		return (35968);
	else
		return (0);
}
