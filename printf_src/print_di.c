/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/21 10:39:50 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				sign(t_flags *data)
{
	if (data->negative || data->plus || data->space)
		return (1);
	return (0);
}

void			add_sign(char **s, t_flags *data)
{
	if (data->negative)
		*s = ft_strcharjoin('-', *s);
	if (data->plus && !data->negative)
		*s = ft_strcharjoin('+', *s);
	if (data->space && !data->plus && !data->negative)
		*s = ft_strcharjoin(' ', *s);
}

char			*print_precision(char *s, int len, int num, t_flags *data)
{
	char		*new;

	new = ft_memalloc(data->p_w + len);
	if (len < data->p_w)
	{
		new = ft_strjoinfree(ft_memset(new, '0', data->p_w - len), s, 1, 1);
		return (new);
	}
	if ((data->precision != -1 && data->zero && !data->star))
		data->zero = 0;
	if (data->p_w == 0 && num == 0)
	{
		s[0] = 0;
		if (sign(data))
			data->width++;
	}
	if (data->precision == 1 && !data->p_w && *s != '0')
		data->precision = -1;
	if (num == 0 && data->precision && !data->p_w)
	{
		free(s);
		s = ft_strnew(0);
	}
	free(new);
	return (s);
}

void			print_decimal_help(t_flags *data, long long *number)
{
	if (*number < 0)
	{
		data->negative = TRUE;
		*number *= -1;
	}
	if (data->zero && data->p_w && !data->star)
		data->zero = 0;
	if (data->zero && data->width && data->minus && data->star)
		data->zero = 0;
}

int				print_decimal(t_flags *data)
{
	char		*s;
	int			len;
	long long	num;

	check_lenght(data, &num);
	print_decimal_help(data, &num);
	if (!(s = ft_itoa_base(num, 10, 0)))
		return (0);
	len = ft_strlen(s);
	if (data->precision >= 0)
		s = print_precision(s, len, num, data);
	if (!data->zero && sign(data))
		add_sign(&s, data);
	if (data->width)
		calculate_width(&s, len, data);
	if (data->zero)
		add_sign(&s, data);
	string_to_buff(s, data);
	free(s);
	return (1);
}
