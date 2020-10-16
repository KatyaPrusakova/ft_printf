/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/16 16:38:53 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_float(t_flags *data, long double *number)
{
	long double num;

	if (data->length == BL)
		num = (long double)va_arg(data->args, long double);
	else
		*number = (double)va_arg(data->args, double);
	if (data->pr_width < 0 && data->precision != -1)
	{
		data->pr_width = 0;
		data->precision = -1;
	}
	if (data->pr_width == 0 && data->precision == -1)
		data->pr_width = 6;
}

void	print_float(t_flags *data)
{
	long double	num;
	char		*s;
	int			len;

	check_float(data, &num);
	s = ft_ftoa(num, data->pr_width);

	if (data->hash && !data->pr_width)
	{
		save_to_buff('.', data);
		return ;
	}
	len = ft_strlen(s);
	
	string_to_buff(s, data);
	free(s);

}
