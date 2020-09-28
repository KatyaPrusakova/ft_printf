/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/28 18:00:34 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static	void	reset(t_flags *data)
{
	data->width = FALSE;
	data->precision = -1;
	data->pr_width = FALSE;
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

static void		string_to_buff(char *s, t_flags *data)
{
	while (*s)
	{
		data->buff[data->len++] = *s;
		s++;
	}
}

static void	print_string(t_flags *data)
{
	char	*s;
	int		i;

	s = (char*)va_arg(data->args,char*);
	if (!s)
		s = "(null)";
	s = ft_strdup(s);
	i = ft_strlen(s);
	/* 	if (data->precision >= i)
		{
			data->precision = -1;
			data->pr_width = 0;
			data->width -= i;
		}
		else */
	if (data->width && !data->minus && data->precision == -1)
	{
		data->width -= i;
		while (data->width > 0)
		{
			save_to_buff(' ', data);
			data->width--;
		}
		string_to_buff(s, data);
	}
	else if (data->width > 0 && data->minus == 1 && data->precision == -1)
	{
		data->width -= i;
		string_to_buff(s, data);
		while (data->width > 0)
		{
			save_to_buff(' ', data);
			data->width--;
		}
	}
	else if (data->width > 0 && !data->minus && data->precision >= 0)
	{
		if (data->pr_width >= i)
		{
			data->width -= i;
		}
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
	else if (data->width > 0 && data->minus == 1 && data->precision >= 0)
	{
		data->width -= i;
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

static void	print_char(t_flags *data)
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
