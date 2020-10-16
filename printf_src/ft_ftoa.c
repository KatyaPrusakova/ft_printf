/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:18:25 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/16 11:17:26 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// str = ft_itoa_base(temp, 10, 0); /* first part before dot */

#include "ft_printf.h"

static	char	ft_sign(long double *number)
{
	char	sign;

	if (( 1 / *number ) < 0)
	{
		*number *= -1;
		sign = '-';
		return (sign);
	}
	return (0);
}


static long double	ft_roundup(int precision, long double f)
{
	long double			rounding;
	unsigned long long	temp;

	rounding = 0.5;
	temp = f + rounding;
	if (temp % 2 != 0 && precision == 0)
		return (0);
	while (precision--)
		rounding /= 10;
	return (rounding);
}

char			*ft_ftoa(long double f, int precision)
{
	unsigned long long	first_part;
	char				*number;
	char				sign;
	char				*after_dot_part;
	int					i;

	i = 1;
	sign = ft_sign(&f);
	f = f + ft_roundup(precision, f);
	first_part = f;
	if (!(number = ft_itoa_base(first_part, 10, 0)))
		return (NULL);
	number = (sign > 0) ? ft_strcharjoin(sign, number) : sign;
	if (!(after_dot_part = ft_strnew(precision + 1)))
	{
		free(number);
		return (0);
	}
	after_dot_part[0] = (precision == 0) ? '\0' : '.';
	while (precision-- > 0)
	{
		f *= 10;
		first_part = f;
		after_dot_part[i++] = first_part % 10 + '0';
	}
	number = ft_strjoinfree(number, after_dot_part);
	return (number);
}
