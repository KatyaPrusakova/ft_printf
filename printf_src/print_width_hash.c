/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:39:19 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/28 09:33:02 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			calculate_width(char **s, int len, t_flags *data)
{
	char		*temp;

	temp = ft_memalloc(data->width + 1);
	if (data->type == 'd' || data->type == 'i' || \
	data->type == 'f' || data->type == 'F')
		data->width = sign(data) && data->width > 0 ? \
		--data->width : data->width;
	if (data->width < len || data->p_w >= data->width)
		data->width = 0;
	if (data->width && data->precision == -1 && **s)
		data->width -= len;
	else if (data->p_w < data->width && data->precision != -1)
		data->width = (data->p_w < len) ? data->width - len : \
		data->width - data->p_w;
	*s = print_width(*s, temp, data->minus, data);
	free(temp);
}

char			*print_width(char *s, char *temp, int minus, t_flags *data)
{
	char	width;

	width = (data->zero > 0 ? '0' : ' ');
	ft_memset(temp, width, data->width);
	s = minus ? ft_strjoinfree(s, temp, 1, 0) : ft_strjoinfree(temp, s, 0, 1);
	return (s);
}

void			print_hash(char **p, t_flags *data)
{
	char			*ox;

	ox = (data->type == 'x') ? "0x" : "0X";
	if (data->hash && data->width && data->zero)
	{
		if (data->p_w)
			*p = ft_strjoinfree(ox, *p, 0, 1);
		else
			string_to_buff(ox, data);
		data->width -= 2;
	}
	if (data->hash && !data->zero)
	{
		*p = ft_strjoinfree(ox, *p, 0, 1);
		if (data->width > 0)
			data->width -= 2;
	}
}

int				print_hash_octal(char **p, t_flags *data)
{
	if (*p[0] == '0')
	{
		string_to_buff(*p, data);
		free(*p);
		return (1);
	}
	else
		*p = ft_strcharjoin('0', *p);
	return (0);
}
