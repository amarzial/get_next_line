/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/28 17:04:37 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int	buffalloc(char **buff,char **start, int *size)
{
	char	*tmp;

	*start = *buff + *size;
	if (!(tmp = (char*)malloc(*size + BUFF_SIZE)))
		return (0);
	ft_memcpy(tmp, *buff, *size);
	*size += BUFF_SIZE;
	ft_memdel((void**)buff);
	*buff = tmp;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_reader	rdr;
	int				cnt;

	if (!rdr.buffer && !(rdr.buffer = (char*)malloc(BUFF_SIZE)))
		return (-1);
	while (!(rdr.eol = ft_memchr(rdr.start, '\n', rdr.size)) && !rdr.stop)
	{
		if (!buffalloc(&rdr.buffer, &rdr.start, &rdr.size))
			return (-1);
		cnt = 0;
		while ((rdr.cnt = read(fd, rdr.start + cnt, BUFF_SIZE - cnt)) > 0)
			cnt += rdr.cnt ;
		if (cnt < BUFF_SIZE)
			rdr.stop = rdr.start + cnt;
	}
	ft_putptr(rdr.eol);
	ft_putchar('\n');
	rdr.eol = (rdr.eol) ? rdr.eol : rdr.stop;
	if (!(*line = (char*)ft_strnew(rdr.eol - rdr.buffer)))
		return (-1);
	ft_memcpy(*line, rdr.buffer, rdr.eol - rdr.buffer);
	return (1);
}
