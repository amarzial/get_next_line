/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:11:00 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/29 16:36:30 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

typedef struct	s_reader
{
	char	*buffer;
	int		stop;
	char	*eol;
	size_t	r_size;
	size_t	b_size;
}				t_reader;

int				get_next_line(const int fd, char **line);

#endif
