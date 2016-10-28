/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:41:26 by wasman            #+#    #+#             */
/*   Updated: 2016/10/20 16:42:27 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*readem(char *arg)
{
	char	*buf;
	int		fd;
	int		len;

	buf = ft_strnew(BUF_SIZE);
	if (buf == NULL)
		return (NULL);
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if ((len = read(fd, buf, BUF_SIZE)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if ((close(fd) == -1))
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (buf);
}
