/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/27 11:15:56 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_string_help(int i, char *s, t_flags *data)
{
	char		width;

	width = (data->zero && data->type == '%') ? '0' : ' ';
	if (data->width && !data->minus && data->precision == -1)
	{
		data->width -= i;
		width_to_buf(width, data);
		string_to_buff(s, data);
		return (1);
	}
	else if (data->width > 0 && data->minus == 1 && data->precision == -1)
	{
		data->width -= i;
		string_to_buff(s, data);
		width_to_buf(width, data);
		return (1);
	}
	return (0);
}

void			print_string_with_presicion(int len, char *s, t_flags *data)
{
	char		*new;

	data->width -= (data->width && data->precision) && (data->p_w >= len) ? \
	len : data->p_w;
	if (!(new = ft_strnew(data->p_w)))
		return ;
	else
		new = ft_strncpy(new, s, data->p_w);
	if (data->width && !data->minus && data->precision)
	{
		width_to_buf((char)' ', data);
		string_to_buff(new, data);
	}
	else if (data->width && data->minus == 1 && data->precision)
	{
		string_to_buff(new, data);
		width_to_buf((char)' ', data);
	}
	else if (data->precision >= 0)
		string_to_buff(new, data);
	free(new);
	return ;
}

void			print_string(t_flags *data)
{
	char		*s;
	int			i;

	s = (char*)va_arg(data->args, char*);
	if (!s)
		s = "(null)";
	i = ft_strlen(s);
	if (data->p_w < 0)
		data->p_w = i;
	if (print_string_help(i, s, data))
		return ;
	if (data->precision != -1)
	{
		print_string_with_presicion(i, s, data);
		return ;
	}
	string_to_buff(s, data);
}

void			print_char(t_flags *data)
{
	if (data->width && data->minus == 0)
	{
		while (data->width > 1)
		{
			save_to_buff(' ', data);
			data->width--;
		}
		save_to_buff(va_arg(data->args, int), data);
	}
	else if (data->width > 0 && data->minus == 1)
	{
		save_to_buff(va_arg(data->args, int), data);
		while (data->width > 1)
		{
			save_to_buff(' ', data);
			data->width--;
		}
	}
	else
		save_to_buff(va_arg(data->args, int), data);
}

void			print_pointer(t_flags *data)
{
	uintmax_t	pointer;
	char		*p;
	int			len;

	pointer = va_arg(data->args, uintmax_t);
	if (!(p = ft_itoa_base(pointer, 16, 0)))
		return ;
	if (data->precision > 0)
		p = print_precision(p, ft_strlen(p), pointer, data);
	p = ft_strjoinfree("0x", p, 0, 1);
	len = ft_strlen(p);
	if (data->width)
		calculate_width(&p, len, data);
	string_to_buff(p, data);
	free(p);
}
