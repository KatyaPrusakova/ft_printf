/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/09 20:27:07 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		help_to_print_string(int i, char *s, t_flags *data)
{
	char	width;

	if (data->zero && data->minus)
		data->zero = 0;
 	width = (data->zero && data->type == '%' ) ? '0' : ' ' ;
	if (data->width && !data->minus && data->precision == -1)
	{
		data->width -= i;
		while (data->width > 0)
		{
			save_to_buff(width, data);
			data->width--;
		}
		string_to_buff(s, data);
		return (1);
	}
	else if (data->width > 0 && data->minus == 1 && data->precision == -1)
	{
		data->width -= i;
		string_to_buff(s, data);
		while (data->width > 0)
		{
			save_to_buff(width, data);
			data->width--;
		}
		return (1);
	}
	return (0);
}

void	print_string(t_flags *data)
{
	char	*s;
	int		i;

	s = (char*)va_arg(data->args,char*);
	if (!s)
		s = "(null)";
	if (data->pr_width <= -1 && !data->width)
	{
		string_to_buff(s, data);
		return ;
	}
	s = ft_strdup(s);
	i = ft_strlen(s);
	if (data->width < 0 || data->pr_width < 0)
	{
		data->width = -data->width;
		data->pr_width = i;
	}
	if (help_to_print_string(i, s, data))
		return ;
	else if (data->width && !data->minus && data->precision)
	{
		if (data->pr_width >= i)
			 data->width -= i;
		else
			data->width -= data->pr_width;
		while (data->width > 0)
		{
			save_to_buff(' ', data);
			data->width--;
		}
		s = ft_strncpy(ft_strnew(data->pr_width), s, data->pr_width);
		string_to_buff(s, data);
	}
	else if (data->width && data->minus == 1 && data->precision)
	{
		if (data->pr_width >= i)
			data->width -= i;
		else
			data->width -= data->pr_width;
		s = ft_strncpy(ft_strnew(data->pr_width), s, data->pr_width);
		string_to_buff(s, data);
		while (data->width > 0)
		{
			save_to_buff(' ', data);
			data->width--;
		}
	}
	else if (data->precision >= 0)
	{
		s = ft_strncpy(ft_strnew(data->pr_width), s, data->pr_width);
		string_to_buff(s, data);
	}
	else
		string_to_buff(s, data);
}

void	print_char(t_flags *data)
{
	if (data->width && data->minus == 0)
	{
		while (data->width > 1)
		{
			save_to_buff(' ', data);
			data->width--;
		}
		save_to_buff(va_arg(data->args,int), data);
	}
	else if (data->width > 0 && data->minus == 1)
	{
		save_to_buff(va_arg(data->args,int), data);
		while (data->width > 1)
		{
			save_to_buff(' ', data);
			data->width--;
		}
	}
	else
		save_to_buff(va_arg(data->args,int), data);
}

void	print_pointer(t_flags *data)
{
	uintmax_t	pointer;
	char		*p;
	int			i;

	pointer = va_arg(data->args,uintmax_t);
	p =  ft_strjoin("0x", ft_itoa_base(pointer, 16, 0));
	i = ft_strlen(p);
	if (help_to_print_string(i, p, data))
		return ;
	else
		string_to_buff(p, data);
	free(p);
}

void	print_percent(t_flags *data)
{
	char	percent;

	percent = data->str[data->pos];
	if (help_to_print_string(1, &percent, data))
		return ;
	else
		save_to_buff(percent, data);
}
