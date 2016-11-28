/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:11:00 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/28 13:11:47 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct	s_reader
{
	char	*buffer;
	char	*start;
	char	*stop;
	int		size;
}				t_reader;

int				get_next_line(const int fd, char **line);

#endif
