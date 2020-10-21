/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:18:25 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/21 12:10:50 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char			ft_sign(long double *number)
{
	char				sign;

	if ((1 / *number) < 0)
	{
		*number *= -1;
		sign = '-';
		return (sign);
	}
	return (0);
}

static long double		ft_roundup(int precision, long double f)
{
	long double			rounding;
	unsigned long long	temp;

	rounding = 0.5;
	temp = f + rounding;
	if (f == rounding)
		return (0);
	if (temp % 2 != 0 && precision == 0 && temp != 1)
		return (0);
	while (precision--)
		rounding /= 10;
	return (rounding);
}

char					*ft_ftoa(long double f, int precision, int hash)
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
	number = (sign > 0) ? ft_strcharjoin(sign, number) : number;
	after_dot_part = ft_strnew(precision + 1);
	after_dot_part[0] = (precision == 0 && !hash) ? '\0' : '.';
	while (precision-- > 0)
	{
		f *= 10;
		first_part = f;
		f -= first_part;
		after_dot_part[i++] = first_part % 10 + '0';
	}
	return (ft_strjoinfree(number, after_dot_part, 1, 1));
}
