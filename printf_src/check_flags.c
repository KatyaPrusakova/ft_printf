/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/30 11:42:15 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	print_uint(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_binary(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}


static void	print_decimal(t_flags *data)
{
	char	*s;
	int		i;

	s = ft_itoa(va_arg(data->args,int));
	if (!s)
	{
		s = "(null)";
	}
	s = ft_strdup(s);
	i = ft_strlen(s);
	string_to_buff(s, data);
}


static void	switch_type(t_flags *data)
{
	char c;

	c = data->str[data->pos];
	// printf("|print %c|\n\n", c);

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

static int	scan_type(t_flags *data)
{
	if (ft_strchr(SPECIFIERS, data->str[data->pos]))
	{
		data->type = data->str[data->pos];
		switch_type(data);
		reset(data);
		return (1);
	}
	return (0);
}

int			add_flags(t_flags *data)
{
		if (data->str[data->pos] == '-')
		{
			data->minus = TRUE;
		}
		else if (data->str[data->pos] == '+')
			{
				data->plus = TRUE;
			}
		else if (data->str[data->pos] == ' ')
			{
				data->space = TRUE;
			}
		else if (data->str[data->pos] == '#')
			{
				data->hash = TRUE;
			}
		else
			return (0);
		return (1);
}

static	int		add_width(t_flags *data)
{
	char	*s;
	int		i;

	i = 10;
	s = ft_strnew(i);
	i =0;
	if (ft_isdigit(data->str[data->pos]))
	{
		while (ft_isdigit(data->str[data->pos]))
		{
			if (data->str[data->pos] == '0')
			{
					data->zero = TRUE;
			}
				s[i] = data->str[data->pos];
				i++;
				data->pos++;
		}
		data->width = ft_atoi(s);
	}
	else
		return (0);
	return (1);
}

static	int	add_precision(t_flags *data)
{
	char	*s;
	int		i;

	i = 10;
	s = ft_strnew(i);
	i =0;
	if (data->str[data->pos] == '.')
	{
		data->precision = TRUE;
		data->pos++;
		if (data->str[data->pos] == '*')
		{
			data->pr_width = va_arg(data->args, int);
			data->pos++;
			return (1);
		}
		while (ft_isdigit(data->str[data->pos]))
		{
			if (data->str[data->pos] == '0')
			{
					data->zero = TRUE;
			}
				s[i] = data->str[data->pos];
				i++;
				data->pos++;
		}
		data->pr_width = ft_atoi(s);
	}
	else
		return (0);
	return (1);
}

static int	parse_flags(t_flags *data)
{
	while (add_flags(data))
		data->pos++;
	add_width(data);
	add_precision(data);
	data->printed += scan_type(data);
	return (1);
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
			data->pos++;
			reset(data);
			parse_flags(data);
		}
	data->pos++;
	}
	print_buff(data);
}
