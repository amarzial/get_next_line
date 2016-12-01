/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/01 19:44:15 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

void	resetreader(t_reader *rdr)
{
	if (rdr->buffer)
		free(rdr->buffer);
	rdr->buffer = 0;
	rdr->el = 0;
	rdr->stop = 0;
	rdr->r_size = 0;
	rdr->b_size = 0;
}

void	resetbuff(t_reader *rdr)
{
	int		chunksize;

	if (rdr->r_size == 0 && rdr->stop == 1)
	{
		if (rdr->buffer)
			free(rdr->buffer);
		ft_memset((void*)rdr, 0, sizeof(t_reader));
		return ;
	}
	if (!rdr->buffer)
		return ;
	if (rdr->el < rdr->buffer || rdr->el > rdr->buffer + rdr->r_size)
	{
		rdr->el = 0;
		return ;
	}
	chunksize = (rdr->buffer + rdr->r_size) - (rdr->el);
	chunksize -= (rdr->stop) ? 0 : 1;
	ft_memmove(rdr->buffer, rdr->el + 1, chunksize);
	rdr->r_size = chunksize;
}

int		buffalloc(t_reader *rdr)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(rdr->r_size + BUFF_SIZE)))
		return (0);
	ft_memcpy(tmp, rdr->buffer, rdr->r_size);
	rdr->b_size = rdr->r_size + BUFF_SIZE;
	ft_memdel((void**)&rdr->buffer);
	rdr->buffer = tmp;
	return (1);
}

int		reading(const int fd, t_reader *rdr)
{
	int		cnt;

	if ((rdr->b_size - rdr->r_size) < BUFF_SIZE)
		if (!buffalloc(rdr))
			return (-1);
	cnt = read(fd, rdr->buffer + rdr->r_size, BUFF_SIZE);
	if (cnt == 0)
		rdr->stop = 1;
	else if (cnt < 0)
		return (-1);
	rdr->r_size += cnt;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_reader	file_readers[MAX_FILES];
	t_reader		*rdr;
	int				res;

	if (fd < 0 || !line)
		return (-1);
	rdr = &(file_readers[fd]);
	resetbuff(rdr);
	while (!(rdr->el = ft_memchr(rdr->buffer, '\n', rdr->r_size)) && !rdr->stop)
	{
		if ((res = reading(fd, rdr)) != 1)
			return (res);
	}
	if (rdr->stop)
	{
		if (rdr->r_size)
			rdr->el = rdr->buffer + rdr->r_size;
		else
			return (0);
	}
	if (!(*line = ft_strnew(rdr->el - rdr->buffer)))
		return (-1);
	ft_memcpy(*line, rdr->buffer, rdr->el - rdr->buffer);
	return (1);
}
