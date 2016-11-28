/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/28 13:11:46 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "get_next_line.h"

int	buffalloc(char **buff,char **start, int *size)
{
	char	*tmp;

	*start = *buff + *size;
	if (!(tmp = (char*)malloc(*size + BUFF_SIZE)))
		return (0);
	ft_memcpy(tmp, *buff, *size);
	size += BUFF_SIZE;
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
	while (!ft_memchr(rdr.buffer, '\n', rdr.size))
	{
		if (!buffalloc(&rdr.buffer, &rdr.start, &rdr.size))
			return (-1);


	}
	if (ft_memchr(buffer, '\n', BUFF_SIZE))
}
