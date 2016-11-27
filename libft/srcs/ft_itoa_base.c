/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:53:17 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/18 19:45:17 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ndigits(int n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	if (n <= 0)
		ret++;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

char		*ft_itoa_base(int n, int base)
{
	char	*out;
	int		index;
	int		size;
	char	*digits;

	digits = "0123456789ABCDEF";
	size = ndigits(n, base);
	if ((out = ft_strnew(size)))
	{
		index = 0;
		if (n == 0)
			out[0] = '0';
		else
		{
			if (n < 0)
				out[0] = '-';
			while (n)
			{
				out[size - index++ - 1] = digits[ft_abs((n % base))];
				n /= base;
			}
		}
	}
	return (out);
}
