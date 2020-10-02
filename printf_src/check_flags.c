// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/02 14:16:38 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_float(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}
static void	print_binary(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}

static int	print_width(char *s, int len, t_flags *data)
{
	char	width;
	char	*temp;

	data->width = (data->width < 0) ? -data->width : data->width;

	temp = ft_memalloc(data->width);
	temp[0] = '-';
	if ((data->precision != -1 && data->zero))
		data->zero = 0;
	width = (data->zero > 0 ? '0' : ' ' );

	if (data->negative && data->precision && !data->zero)
	{
		s = ft_strjoin(temp, s);
		data->width--;
	}
	if (data->width && !data->minus && data->precision == -1)
	{
		data->width -= len;
		if (data->zero && data->negative)
		{
			data->width--;
			save_to_buff('-', data);
		}
		while (data->width > 0)
		{
			save_to_buff(width, data);
			data->width--;
		}
		string_to_buff(s, data);
		return (1);
	}
	if (data->width && data->minus && data->precision == -1)
	{
		data->width -= len;
		string_to_buff(s, data);
		while (data->width > 0)
		{
			save_to_buff(width, data);
			data->width--;
		}
		return (1);
	}
	else if (data->pr_width < data->width && !data->minus && data->precision != -1)
	{

		data->width = (data->pr_width < len)? data->width - len : data->width - data->pr_width ;
		ft_memset(temp, ' ', data->width);
		s = ft_strjoin(temp, s);
		string_to_buff(s, data);
		return (1);
	}
	else if (data->pr_width < data->width && data->minus && data->precision != -1)
	{

		data->width = (data->pr_width < len) ? data->width - len : data->width - data->pr_width ;
		ft_memset(temp, ' ', data->width);
		s = ft_strjoin(s, temp);
		string_to_buff(s, data);
		return (1);
	}
	return (0);
}

static char	*print_precision(char *s, int len, int num, t_flags *data)
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
	if (data->pr_width == 0 && num == 0)
		s = " ";
	return (s);
}

static void	print_uint(t_flags *data)
{
	char	*s;
	int		len;
	unsigned int		num;

	num = va_arg(data->args, unsigned int);
	if (data->minus && data->zero)
		data->zero = 0;
	s = ft_itoa_base(num, 10, 0);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	s = ft_strdup(s);
	if (data->precision != -1 && !data->pr_width && !data->width)
		return ;
	if (data->precision > 0)
		s = print_precision(s, len, num, data);
	if (print_width(s, len, data))
		return ;
	else
	{
		string_to_buff(s, data);
	}
}

static	void	check_lenght(t_flags *data)
{

	else if (data->length = H)

	else if (data->length = HH)

	else if (data->length = L)

	else if (data->length = LL)

	else if (data->length = BL)

	else if (data->length = J)

	else if (data->length = Z)

	else if (data->length = T)

}

static void	print_decimal(t_flags *data)
{
	char	*s;
	int		len;
	long long	num;

	check_lenght(data);
	num = va_arg(data->args, int);

	if (num < 0)
	{
		data->negative = TRUE;
		num = -num;
	}
	if (data->minus && data->zero)
		data->zero = 0;
	if (data->space)
		save_to_buff(' ', data);
	s = ft_itoa_base(num, 10, 0);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	s = ft_strdup(s);
	if (data->precision != -1 && !data->pr_width && !data->width)
		return ;
	if (data->precision > 0)
		s = print_precision(s, len, num, data);
	if (print_width(s, len, data))
		return ;
	else
	{
		if (data->negative)
			save_to_buff('-', data);
		string_to_buff(s, data);
	}
}

// printf("precision %s %s\n",new_s, s);

static void	print_hex(t_flags *data)
{
	uintmax_t	pointer;
	char		*p;
	int			len;

	pointer = va_arg(data->args,uintmax_t);
	p = (data->type == 'x') ? ft_itoa_base(pointer, 16, 0) : ft_itoa_base(pointer, 16, 1);
	len = ft_strlen(p);
	if (data->minus && data->zero)
		data->zero = 0;
	if (data->precision != -1 && !data->pr_width && !data->width)
		return ;
	if (data->precision > 0)
		p = print_precision(p, len, pointer, data);
	if (print_width(p, len, data))
		return ;
	else
	{
		if (data->negative)
			save_to_buff('-', data);
		string_to_buff(p, data);
	}
	free(p);
}

static void	print_octal(t_flags *data)
{
	uintmax_t	pointer;
	char		*p;
	int			len;

	pointer = va_arg(data->args,uintmax_t);
	p = (data->type == 'o') ? ft_itoa_base(pointer, 8, 0) : ft_itoa_base(pointer, 8, 1);
	len = ft_strlen(p);
	if (data->minus && data->zero)
		data->zero = 0;
	if (data->precision != -1 && !data->pr_width && !data->width)
		return ;
	if (data->precision > 0)
		p = print_precision(p, len, pointer, data);
	if (print_width(p, len, data))
		return ;
	else
	{
		if (data->negative)
			save_to_buff('-', data);
		string_to_buff(p, data);
	}
	free(p);
}


static void	switch_type(t_flags *data)
{
	data->type = data->str[data->pos];
	if (data->type == 'd' || data->type == 'i' || data->type == 'D')
		print_decimal(data);
	else if (data->type == 'c' || data->type == 'C')
		print_char(data);
	else if (data->type == 's' || data->type == 'S')
		print_string(data);
	else if (data->type == 'p' || data->type == 'P')
		print_pointer(data);
	else if (data->type == 'f' || data->type == 'F')
		print_float(data);
	else if (data->type == 'x' || data->type == 'X')
		print_hex(data);
	else if (data->type == 'u' || data->type == 'U')
		print_uint(data);
	else if (data->type == 'o' || data->type == 'O')
		print_octal(data);
	else if (data->type == 'b' || data->type == 'B')
		print_binary(data);
	else if (data->type == '%')
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
		else if (data->str[data->pos] == '0') /* maybe to delete */
			{
				data->zero = TRUE;
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
	if (data->str[data->pos] == '*')
	{
		data->star = TRUE;
		data->width = va_arg(data->args, int);
		if (data->width < 0)
			data->minus = TRUE;
		data->pos++;
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
			data->star = TRUE;
			data->pr_width = va_arg(data->args, int);
			data->pos++;
			return ;
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
