/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:16:00 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/16 11:16:05 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_lenght(t_flags *data)
{
	if (data->str[data->pos] == 'h')
		if (data->str[data->pos + 1] == 'h')
			data->length = HH;
		else
			data->length = H;
	else if (data->str[data->pos] == 'l')
		if (data->str[data->pos + 1] == 'l')
			data->length = LL;
		else
			data->length = L;
	else if (data->str[data->pos] == 'L')
		data->length = BL;
	else if (data->str[data->pos] == 'j')
		data->length = J;
	else if (data->str[data->pos] == 'z')
		data->length = Z;
	while (ft_strchr(LENGTH, data->str[data->pos]))
		data->pos++;
}

void	check_lenght(t_flags *data, long long *number)
{
	if (data->length == H)
		*number = (short int)va_arg(data->args, int);
	else if (data->length == HH)
		*number = (signed char)va_arg(data->args, signed char*);
	else if (data->length == L)
		*number = (long int)va_arg(data->args, long int);
	else if (data->length == LL)
		*number = (long long int)va_arg(data->args, long long int);
	else if (data->length == J)
		*number = (intmax_t)va_arg(data->args, intmax_t);
	else if (data->length == Z)
		*number = (size_t)va_arg(data->args, size_t);
	else
		*number = (int)va_arg(data->args, int);
}

void	check_unsigned_lenght(t_flags *data, long long *n)
{
	if (data->length == H)
		*n = (unsigned short int)va_arg(data->args, int);
	else if (data->length == HH)
		*n = (unsigned char)va_arg(data->args, unsigned int);
	else if (data->length == L)
		*n = (unsigned long int)va_arg(data->args, unsigned long int);
	else if (data->length == LL)
		*n = (unsigned long long int)va_arg(data->args, unsigned long long int);
	else if (data->length == J)
		*n = (uintmax_t)va_arg(data->args, uintmax_t);
	else if (data->length == Z)
		*n = (size_t)va_arg(data->args, size_t);
	else
		*n = (unsigned int)va_arg(data->args, unsigned int);
}
