/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uoxb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:47:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/21 13:37:51 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_binary(t_flags *data)
{
	long long		pointer;
	char			*p;
	int				len;

	if (data->zero && data->p_w)
		data->zero = 0;
	check_unsigned_lenght(data, &pointer);
	if (!(p = ft_itoa_base(pointer, 2, 0)))
		p = ft_strdup("null");
	len = ft_strlen(p);
	if (*p == '0')
		data->hash = 0;
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (data->hash > 0)
		print_hash(&p, data);
	if (data->width)
		calculate_width(&p, len, data);
	string_to_buff(p, data);
	free(p);
}

void				print_hex(t_flags *data)
{
	long long		pointer;
	char			*p;
	int				len;

	if (data->zero && data->p_w)
		data->zero = 0;
	check_unsigned_lenght(data, &pointer);
	if (!(p = (data->type == 'x') ? ft_itoa_base(pointer, 16, 0) : \
	ft_itoa_base(pointer, 16, 1)))
		p = ft_strdup("null");
	len = ft_strlen(p);
	if (*p == '0')
		data->hash = 0;
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (data->hash > 0)
		print_hash(&p, data);
	if (data->width)
		calculate_width(&p, len, data);
	string_to_buff(p, data);
	free(p);
}

void				print_octal(t_flags *data)
{
	long long		pointer;
	char			*p;
	int				len;

	check_unsigned_lenght(data, &pointer);
	p = (data->type == 'o') ? ft_itoa_base(pointer, 8, 0) : \
	ft_itoa_base(pointer, 8, 1);
	if (!p)
		p = "null";
	if (data->hash && print_hash_octal(&p, data))
		return ;
	len = ft_strlen(p);
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (!data->zero && sign(data))
		add_sign(&p, data);
	if (data->width)
		calculate_width(&p, len, data);
	if (data->zero)
		add_sign(&p, data);
	string_to_buff(p, data);
	free(p);
}

void				print_uint(t_flags *data)
{
	char			*s;
	int				len;
	long long		num;

	check_unsigned_lenght(data, &num);
	if (data->zero && data->p_w)
		data->zero = 0;
	s = ft_itoa_base(num, 10, 0);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (data->precision >= 0)
		s = print_precision(s, len, num, data);
	if (data->width)
		calculate_width(&s, len, data);
	string_to_buff(s, data);
	free(s);
}

void				print_percent(t_flags *data)
{
	char			percent;

	percent = data->s[data->pos];
	if (print_string_help(1, &percent, data))
		return ;
	else
		save_to_buff(percent, data);
}
