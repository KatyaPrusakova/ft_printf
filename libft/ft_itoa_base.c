/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/29 11:57:57 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(uintmax_t n, int base)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(uintmax_t num, int base)
{
	char		*str;
	char		*format;
	int			len;
	char		s;

	format = "0123456789abcdef";
	len = ft_len(num, base);
	if (!(str = ft_strnew(len)))
		return (0);
	while (len)
	{
		len--;
		str[len] = format[num % base];
		num = num / base;
	}
	return (str);
}
