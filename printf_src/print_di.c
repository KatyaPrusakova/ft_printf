/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/15 18:05:58 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sign(t_flags *data)
{
	if (data->negative || data->plus || data->space)
		return (1);
	return (0);
}

void			add_sign(char **s, t_flags *data)
{
	if (data->negative )
		*s = ft_strcharjoin('-', *s);
	if (data->plus && !data->negative)
		*s = ft_strcharjoin('+', *s);
	if (data->space && !data->plus && !data->negative)
		*s = ft_strcharjoin(' ', *s);
}

void			calculate_width(char **s, int len, t_flags *data)
{
	char	*temp;

	data->width = (data->width < 0) ? -data->width : data->width;
	temp = ft_memalloc(data->width + 1);
	if (data->type == 'd' || data->type == 'i')
		data->width = (sign(data) && data->width > 0 ) ? --data->width : data->width;
	if (data->width < len)
		data->width = 0;
	if (data->pr_width > data->width)
	{
		data->width = 0;
	}
	if (data->width && data->precision == -1 && **s)
	{
		data->width -= len;
	}
	else if (data->pr_width < data->width && data->precision != -1)
	{
		data->width = (data->pr_width < len)? data->width - len : data->width - data->pr_width;
	}
	*s = (data->minus > 0 && data->width) ? print_width_minus(*s, temp, data) : print_width(*s, temp, data);
}

char				*print_width(char *s, char *temp, t_flags *data)
{
	char	width;

	width = (data->zero > 0 ? '0' : ' ' );

	if (data->width && data->precision == -1)
	{
		ft_memset(temp, width, data->width);
		s = ft_strjoin(temp, s);
	}
	else if (data->pr_width && data->width && data->precision != -1)
	{
		ft_memset(temp, width, data->width);
		s = ft_strjoin(temp, s);
	}
	return (s);
}

char				*print_width_minus(char *s, char *temp, t_flags *data)
{
	char	width;

	width = (data->zero > 0 ? '0' : ' ' );
	if (data->width && data->precision == -1)
	{
		ft_memset(temp, width, data->width);
		s = ft_strjoin(s, temp);
	}
	else if (data->pr_width && data->width && data->precision != -1)
	{
		ft_memset(temp, width, data->width);
		s = ft_strjoin(s, temp);
	}
	return (s);
}

char		*print_precision(char *s, int len, int num, t_flags *data)
{
	char		*new_s;

	new_s = ft_memalloc(data->pr_width + len);

	if (len < data->pr_width)
	{
		ft_memset(new_s, '0', data->pr_width - len);
		new_s = ft_strjoin(new_s, s);
		return (new_s);
		data->zero = 0;
	}
	else if (data->star && data->pr_width < 0)
	{
		data->pr_width = 1;
		data->precision = -1;
	}
	if ((data->precision != -1 && data->zero))
		data->zero = 0;
	else if (data->precision && data->pr_width == 0)
	{
		data->pr_width = 0;
		data->precision = -1;
	}
	if (data->pr_width == 0 && num == 0)
	{
		s[0] = 0;
		if (sign(data))
			data->width++;
	}
	if (data->precision == 1 && !data->pr_width && *s != '0')
	{
		data->precision = -1;
	}
	return (s);
}


void	print_decimal_help(t_flags *data, long long *number)
{
	if (*number < 0)
	{
		data->negative = TRUE;
		*number *= -1;
	}
	data->width = (data->width < 0) ? -data->width : data->width;
	if (data->minus && data->zero)
		data->zero = 0;
	if (data->zero && data->pr_width)
		data->zero = 0;
/* 	if (data->pr_width > data->width && data->precision != -1)
		data->width = 0; */
}

void	print_decimal(t_flags *data)
{
	char	*s;
	int		len;
	long long	num;

	check_lenght(data, &num);
	print_decimal_help(data, &num);
	if (!(s = ft_itoa_base(num, 10, 0)))
		s = ft_strdup("(null)");
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
}
