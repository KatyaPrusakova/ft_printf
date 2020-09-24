/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/24 15:02:57 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static void	print_decimal(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_string(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_pointer(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_float(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_octal(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_hex(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_percent(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_uint(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_binary(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}

static void		save_to_buff(char c, t_flags *data)
{
	if (data->len < 1024)
	{
		data->buff[data->len] = c;
		data->len++;
	}
}

static void		print_buff(t_flags *data)
{
	write(1, data->buff, data->len);
}


static void	print_char(t_flags *data)
{
	// printf("|buff string is %s|", data->buff);
	if (data->width == TRUE)
		printf("|buff width is %d|", data->width);
	else if (data->zero == TRUE)
		printf("|buff zero is %d|", data->zero);
	else
	{
		save_to_buff(va_arg(data->args,int), data);
	}

}

void	add_flags(t_flags *data)
{
	while (ft_strchr(FLAGS,data->str[pos]))
	{
		if (data->str[pos] == '-')
			data->minus = TRUE;
		else if (data->str[pos] == '+')
			data->plus = TRUE;
		else if (data->str[pos] == ' ')
			data->space = TRUE;
		else if (data->str[pos] == '0')
			data->zero = TRUE;
		else if (data->str[pos] == '#')
			data->hash = TRUE;
		else if (data->str[pos] >= '1' && data->str[pos] <= '9')
			data->width = TRUE;
		else if (data->str[pos] == '.')
			data->precision = TRUE;
		pos++;
	}
}

static void	switch_type(t_flags *data)
{
	char c;

	c = data->type;
	printf("|swith type is %c|", c);

	if (c == 'd' || c == 'i' || c == 'D')
		print_decimal(data);
	else if (c == 'c' || c == 'C')
		print_char(data);
	else if (c == 's' || c == 'S')
		print_string(data);
	else if (c == 'p' || c == 'P')
		print_pointer(data);
	else if (c == 'f' || c == 'F')
		print_float(data);
	else if (c == 'x' || c == 'X')
		print_hex(data);
	else if (c == 'u' || c == 'U')
		print_uint(data);
	else if (c == 'o' || c == 'O')
		print_octal(data);
	else if (c == 'b' || c == 'B')
		print_binary(data);
	else if (c == '%')
		print_percent(data);
	else
		return ;
}

void	parse_flags(char *format, t_flags *data)
{
	data->str = format;

	// printf("|it got you %s %d|\n", data->str, data->format_size);
	while (data->str[data->pos])
	{
		printf("|loop %s|\n", data->str);
		if (ft_strchr(FLAGS, data->str[data->pos]))
			add_flags(data);
		if (ft_strchr(SPECIFIERS, data->str[data->pos]))
			switch_type(data);
		data->pos++;
	}
}

void	parse_menu(char *format, t_flags *data)
{
	while (*format)
	{
		if (*format != '%')
		{
			save_to_buff(data->str[data->pos], data);
			data->printed++;
		}
		else if (*format == '%')
		{
			++format;
			if (*format == 0 || !ft_strchr(CASE, *format))
				break;
			while (ft_strchr(FLAGS, *format))
			{
				add_flags(data, (int)*format);
				format++;
			}
			if (ft_strchr(SPECIFIERS, *format))
			{
				switch_type(data);
				format++;
			}
		}
		format++;
	}
	print_buff(data);
}
