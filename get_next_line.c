/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/29 16:51:24 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

void	resetbuff(t_reader *rdr)
{
	int		chunksize;

	if (!rdr->buffer)
		return ;
	chunksize = (rdr->buffer + rdr->r_size) - (rdr->eol + 1);
	ft_memmove(rdr->buffer, rdr->eol + 1, chunksize);
	rdr->r_size = chunksize;
}

int		buffalloc(t_reader *rdr)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(rdr->b_size + BUFF_SIZE)))
		return (0);
	ft_memcpy(tmp, rdr->buffer, rdr->b_size);
	rdr->b_size += BUFF_SIZE;
	ft_memdel((void**)&rdr->buffer);
	rdr->buffer = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_reader	rdr;
	int				cnt;

	resetbuff(&rdr);
	while (!(rdr.eol = ft_memchr(rdr.buffer, '\n', rdr.r_size)) && !rdr.stop)
	{
		if (rdr.r_size == rdr.b_size)
			if (!buffalloc(&rdr))
				return (-1);
		cnt = read(fd, rdr.buffer + rdr.r_size, rdr.b_size - rdr.r_size);
		if (cnt == 0)
			rdr.stop = 1;
		else if (cnt < 0)
			return (-1);
		rdr.r_size += cnt;
	}
	if (rdr.stop)
		return (0);
	if (!(*line = ft_strnew(rdr.eol - rdr.buffer)))
		return (-1);
	ft_memcpy(*line, rdr.buffer, rdr.eol - rdr.buffer);
	return (1);
}
