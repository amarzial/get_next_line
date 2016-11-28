/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:11:00 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/28 16:50:45 by amarzial         ###   ########.fr       */
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
	char	*eol;
	int		cnt;
	int		size;
}				t_reader;

int				get_next_line(const int fd, char **line);

#endif
