/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:11:00 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/02 21:58:49 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

typedef struct	s_reader
{
	int		fd;
	char	*buffer;
	char	*el;
	int		stop;
	size_t	r_size;
	size_t	b_size;
}				t_reader;

int				get_next_line(const int fd, char **line);

#endif
