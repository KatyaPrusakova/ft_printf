/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:33:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/07 14:55:59 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_len(uintmax_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int     ft_itoa_float(double number, int pr_width)
{
    char *str;
    double    temp;
    size_t len;
    size_t i;

    len = ft_len(number);
    i = 0;
    temp = number;
    if (!(str = ft_strnew(len)))
		return (0);
    while (len--)
    {
        str[len] = '0' + temp / 10;
        temp = temp % 10;
    }
    

}