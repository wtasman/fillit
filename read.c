/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:41:26 by wasman            #+#    #+#             */
/*   Updated: 2016/10/15 01:12:34 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*readem(char *arg)
{
	char	*buf;
	int		fd;
	int		len;

	buf = ft_strnew(BUF_SIZE);
	fd = open(arg, O_RDONLY);
	len = read(fd, buf, BUF_SIZE);
	close(fd);
	return (buf);
}
