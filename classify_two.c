/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:39:12 by whickey           #+#    #+#             */
/*   Updated: 2016/11/05 22:41:06 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	is_right_t(unsigned short tet)
{
	if (!(tet ^ 19520) || !(tet ^ 9760) || !(tet ^ 4880) || !(tet ^ 1220) \
	|| !(tet ^ 610) || !(tet ^ 305))
		return (19520);
	else
		return (0);
}

unsigned short	is_upside_down_t(unsigned short tet)
{
	if (!(tet ^ 19968) || !(tet ^ 9984) || !(tet ^ 1248) || !(tet ^ 624) \
	|| !(tet ^ 78) || !(tet ^ 39))
		return (19968);
	else
		return (0);
}

unsigned short	is_normal_j(unsigned short tet)
{
	if (!(tet ^ 17600) || !(tet ^ 8800) || !(tet ^ 4400) || !(tet ^ 1100) \
	|| !(tet ^ 550) || !(tet ^ 275))
		return (17600);
	else
		return (0);
}

unsigned short	is_downward_j(unsigned short tet)
{
	if (!(tet ^ 57856) || !(tet ^ 28928) || !(tet ^ 3616) || !(tet ^ 1808) \
	|| !(tet ^ 226) || !(tet ^ 113))
		return (57856);
	else
		return (0);
}

unsigned short	is_upside_down_j(unsigned short tet)
{
	if (!(tet ^ 51328) || !(tet ^ 25664) || !(tet ^ 12832) || !(tet ^ 3208) \
	|| !(tet ^ 1604) || !(tet ^ 802))
		return (51328);
	else
		return (0);
}
