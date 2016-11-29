/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/29 15:44:30 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

void	resetbuff(t_reader *rdr)
{
	int		size;

	if (!rdr->buffer)
		return ;
	size = rdr->size - (rdr->eol - rdr->buffer + 1);
	ft_memmove(rdr->buffer, rdr->eol + 1, size);
	rdr->start = rdr->buffer + size;
	ft_memset(rdr->start, 0, rdr->size - size);
}

int		buffalloc(char **buff,char **start, int *size)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(*size + BUFF_SIZE)))
		return (0);
	ft_memcpy(tmp, *buff, *size);
	*start = tmp + *size;
	*size += BUFF_SIZE;
	ft_memdel((void**)buff);
	*buff = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_reader	rdr;
	int				cnt;

	resetbuff(&rdr);
	if (!rdr.buffer && !(rdr.buffer = (char*)malloc(BUFF_SIZE)))
		return (-1);
	while (!(rdr.eol = ft_memchr(rdr.buffer, '\n', rdr.size)) && !rdr.stop)
	{
		if (!buffalloc(&rdr.buffer, &rdr.start, &rdr.size))
			return (-1);
		cnt = 0;
		while ((rdr.cnt = read(fd, rdr.start + cnt, BUFF_SIZE - cnt)) > 0)
			cnt += rdr.cnt ;
		if (cnt < BUFF_SIZE)
			rdr.stop = rdr.start + cnt;
	}
	rdr.eol = (rdr.eol) ? rdr.eol : rdr.stop;
	if (!(*line = (char*)ft_strnew(rdr.eol - rdr.buffer)))
		return (-1);
	ft_memcpy(*line, rdr.buffer, rdr.eol - rdr.buffer);
	return (1);
}
