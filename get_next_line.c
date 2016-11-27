/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/27 16:26:44 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char		buffer[BUFF_SIZE];
	static char		*stop;
	int				rb;

	if (!(*line = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while ((rb = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if((stop = ft_memccpy(*line, buffer, BUFF_SIZE)))
			
	}
	if (ft_memchr(buffer, '\n', BUFF_SIZE))
}
