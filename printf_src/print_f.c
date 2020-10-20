
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/19 17:52:05 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*check_float(t_flags *data, long double *number)
{
	if (data->length == BL)
		*number = (long double)va_arg(data->args, long double);
	else
		*number = (double)va_arg(data->args, double);
	if (( 1 / *number ) < 0)
	{
		data->negative = TRUE;
		*number *= -1;
	}
	if (data->precision != -1 )
	{
		if (data->pr_width < 0)
		{
			data->pr_width = 0;
			data->precision = -1;
		}

	}
	if (data->pr_width == 0 && data->precision == -1)
	{
		data->pr_width = 6;
	}
	return (ft_ftoa(*number, data->pr_width, data->hash));
}

void	print_float(t_flags *data)
{
	long double	num;
	char		*s;
	int			len;

	s = check_float(data, &num);
	len = ft_strlen(s);
	if (!data->zero && sign(data))
		add_sign(&s, data);

	if (data->width)
		calculate_width(&s, len, data);
	if (data->zero)
		add_sign(&s, data);

	string_to_buff(s, data);
	free(s);

}
