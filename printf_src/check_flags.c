/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/25 14:42:00 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static	void	reset(t_flags *data)
{
	data->width = FALSE;
	data->precision = FALSE;
	data->lenght = FALSE;

	data->hash = FALSE;
	data->plus = FALSE;
	data->minus = FALSE;
	data->space = FALSE;
	data->zero = FALSE;
	// pf->precision = -1;
}


static void	print_decimal(t_flags *data)
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
	printf("|break %c|\n", c);
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

static void	print_string(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}

static void	print_char(t_flags *data)
{
	// printf("|buff string is %s|", data->buff);
	if (data->width > 0)
	{
		while (data->width--)
		{
			save_to_buff(' ', data);
		}
	}
		printf("|buff width is %d|\n", data->width);
	if (data->zero == TRUE)
		printf("|buff zero is %d|\n", data->zero);
	else
	{
		save_to_buff(va_arg(data->args,int), data);
	}

}

static void	switch_type(t_flags *data)
{
	char c;

	c = data->str[data->pos];
	printf("|print %c|\n\n", c);

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

void	add_flags(t_flags *data)
{
	while (ft_strchr(FLAGS, data->str[data->pos]))
	{
		if (data->str[data->pos] == '-')
			data->minus = TRUE;
		else if (data->str[data->pos] == '+')
			data->plus = TRUE;
		else if (data->str[data->pos] == ' ')
			data->space = TRUE;
		else if (data->str[data->pos] == '#')
			data->hash = TRUE;
		data->pos++;
	}
}

static	void	add_width(t_flags *data)
{
	if (data->str[data->pos] == '0')
			data->zero = TRUE;
	if (data->str[data->pos] >= '1' && data->str[data->pos] <= '9')
	{
			data->width = data->str[data->pos] - '0';
			printf("width |%d\n", data->width);
			data->pos++;
	}
	else
	{
		return ;
	}
}

static	void	add_precision(t_flags *data)
{

	if (data->str[data->pos] == '.')
	{
		data->precision = TRUE;
		data->pos++;
	}
	else
	{
		return ;
	}
}

void	parse_flags(t_flags *data)
{
	// printf("|it got you %s %d|\n", data->str, data->format_size);
		printf("|loop %c|\n", data->str[data->pos]);
		if (ft_strchr(FLAGS, data->str[data->pos]))
		{
			add_flags(data);
			add_width(data);
			add_precision(data);
		}
		else
		{
			return ;
		}
}

void	parse_menu(t_flags *data)
{
	while (data->str[data->pos] != '\0')
	{
		if (data->str[data->pos] != '%')
		{
			save_to_buff(data->str[data->pos], data);
			data->printed++;
		}
		else if (data->str[data->pos] == '%')
		{
			while (ft_strchr(CASE, data->str[data->pos+1]))
			{
				data->pos++;
				parse_flags(data);
				if (ft_strchr(SPECIFIERS, data->str[data->pos]))
						switch_type(data);
						reset(data);
						break;
			}
		}
	data->pos++;
	}
	print_buff(data);
}
