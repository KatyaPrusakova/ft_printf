/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/30 17:59:45 by eprusako         ###   ########.fr       */
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

static int	print_width(char *s, int i, t_flags *data)
{
	char	width;

	width = (data->zero > 0 ? '0' : ' ' );
	if (data->width && !data->minus && data->precision == -1 && s[0] != '-')
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
	else if (data->width > 0 && !data->minus && data->precision == -1 && s[0] == '-')
	{
		if (data->zero)
		{
			save_to_buff('-', data);
			s = ft_strsub(s, 1, (i-1)); /* make string witout minus */
		}
		data->width -= (i); /* i minus one because of minus signed*/
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

static int	print_precision(char *s, int i, t_flags *data)
{
	size_t		diff;
	char	*new_s = NULL;

	diff = 0;
	/* if (i >= data->pr_width)
		return ; */
	if (i < data->pr_width)
	{
		diff = data->pr_width - i;
		ft_memset(new_s, '0', diff);
		ft_strjoin(new_s, s);
		printf("%s\n", new_s);
	}
	return (0);
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
	if (print_width(s, i, data))
		printf("%s\n", s);

	if (print_precision(s, i, data))
		return ;
	else if (data->precision >= 0 && !data->minus && s[0] == '-')
	{
		save_to_buff('-', data);
		s = ft_strsub(s, 1, (i-1)); /* make string witout minus */
		data->width = data->pr_width;
		data->width -= (i-1); /* i minus one because of minus signed*/
		while (data->width > 0)
		{
			save_to_buff('0', data);
			data->width--;
		}
		string_to_buff(s, data);
	}
	else if (data->precision >= 0 && !data->minus)
	{
		data->width = data->pr_width;
		data->width -= i;
		while (data->width > 0)
		{
			save_to_buff('0', data);
			data->width--;
		}
		string_to_buff(s, data);
	}
	else
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

static	void		add_width(t_flags *data)
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
}

static	void	add_precision(t_flags *data)
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
}

static	void	add_lenght(t_flags *data)
{
	if (data->str[data->pos] == 'h')
		if (data->str[data->pos + 1] == 'h')
			data->length = HH;
		else
			data->length = H;
	else if (data->str[data->pos] == 'l')
		if (data->str[data->pos + 1] == 'l')
			data->length = LL;
		else
			data->length = L;
	else if (data->str[data->pos] == 'L')
		data->length = BL;
	else if (data->str[data->pos] == 'j')
		data->length = J;
	else if (data->str[data->pos] == 'z')
		data->length = Z;
	else if (data->str[data->pos] == 't')
		data->length = T;
	while (ft_strchr(LENGTH, data->str[data->pos]))
		data->pos++;
}

static int	parse_flags(t_flags *data)
{
	while (add_flags(data))
		data->pos++;
	add_width(data);
	add_precision(data);
	add_lenght(data);
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
