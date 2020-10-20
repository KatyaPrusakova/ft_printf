/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:16:00 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/20 16:19:04 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			switch_type(t_flags *data)
{
	data->type = data->s[data->pos];
	if (data->type == 'd' || data->type == 'i' || data->type == 'D')
		print_decimal(data);
	else if (data->type == 'c' || data->type == 'C')
		print_char(data);
	else if (data->type == 's' || data->type == 'S')
		print_string(data);
	else if (data->type == 'p' || data->type == 'P')
		print_pointer(data);
	else if (data->type == 'f' || data->type == 'F')
		print_float(data);
	else if (data->type == 'x' || data->type == 'X')
		print_hex(data);
	else if (data->type == 'u' || data->type == 'U')
		print_uint(data);
	else if (data->type == 'o' || data->type == 'O')
		print_octal(data);
	else if (data->type == 'b' || data->type == 'B')
		print_binary(data);
	else if (data->type == '%')
		print_percent(data);
	else if (data->type == 'n')
		data->type = va_arg(data->args, uintmax_t);
	else
		return ;
}

int		scan_type(t_flags *data)
{
	while (add_flags(data))
		data->pos++;
	add_width(data);
	add_precision(data);
	add_lenght(data);
	if (data->zero && data->minus && !data->star)
		data->zero = 0;
	if (ft_strchr(SPECIFIERS, data->s[data->pos]))
	{
		data->type = data->s[data->pos];
		switch_type(data);
		reset(data);
		return (1);
	}
	return (0);
}

int		parse_menu(t_flags *data)
{
	while (data->s[data->pos] != '\0')
	{
		if (data->s[data->pos] != '%')
			save_to_buff(data->s[data->pos], data);
		else if (data->s[data->pos] == '%' && data->s[data->pos + 1] != '\0')
		{
			data->pos++;
			reset(data);
			if (!scan_type(data))
				return (0);
		}
		data->pos++;
	}
	return (print_buff(data));
}
