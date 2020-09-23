/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/23 18:50:39 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static void	print_decimal(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}

static void	print_char(t_flags *data)
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


void	add_flags(t_flags *data)
{
	size_t		i;

	i = 0;
	while (data->str[i] != '\0')
	{
		if (data->str[i] == '-')
			data->minus = TRUE;
		else if (data->str[i] == '+')
			data->plus = TRUE;
		else if (data->str[i] == ' ')
			data->space = TRUE;
		else if (data->str[i] == '0')
			data->zero = TRUE;
		else if (data->str[i] == '#')
			data->hash = TRUE;
		else
			return ;
		i++;
	}
}

static void	switch_type(const char *str, t_flags *data)
{
	char c;

	c = str[data->pos];
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

static void		save_to_buff(char c, t_flags *data)
{
	if (data->len < 1024)
	{
		data->buff[data->len] = c;
		data->len++;
	}
}

void	parse_flags(char *format, t_flags *data)
{
	data->str = format;
	data->format_size = ft_strlen(format);
	printf("|it got you %s %d|", data->str, data->format_size);
	while (data->str[data->pos])
	{
		if (ft_strchr(CASE, data->str[data->pos]))
			add_flags(data);
		else if (ft_strchr(SPECIFIERS, data->str[data->pos]))
			switch_type(data);
		else
		{
			save_to_buff(format[data->pos], data);
		}
		data->pos++;
	}
}
