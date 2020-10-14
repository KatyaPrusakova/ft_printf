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

void	print_binary(t_flags *data)
{
	printf("|buff string is %s|", data->buff);
}

// printf("precision %s %s\n",new_s, s);

char *print_hash(char *p, t_flags *data)
{
	if (data->hash && data->width && data->zero)
	{
		if (data->pr_width)
			p = (data->type == 'x') ? ft_strjoin(OX, p) : ft_strjoin(BIGOX, p);
		else
			data->type == 'x' ? string_to_buff(OX, data) : string_to_buff(BIGOX, data) ;
		data->width -= 2;
	}
	if (data->hash && !data->zero)
	{
		p = (data->type == 'x') ? ft_strjoin(OX, p) : ft_strjoin(BIGOX, p);
		if (data->width > 0)
			data->width -= 2;
	}
	return (p);
}

void	print_hex(t_flags *data)
{
	long long		pointer;
	char		*p;
	int			len;

	check_unsigned_lenght(data, &pointer);
	p = (data->type == 'x') ? ft_itoa_base(pointer, 16, 0) : ft_itoa_base(pointer, 16, 1);

	len = ft_strlen(p);
	if (data->minus && data->zero)
		data->zero = 0;
	if (*p == '0')
		data->hash = 0;
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (data->hash > 0)
		p = print_hash(p, data);
	if (!data->zero && sign(data))
		add_sign_nozero(&p, data);

	if (data->width)
		calculate_width(&p, len, data);

	if (data->zero)
		add_sign_zero(&p, data);
	string_to_buff(p, data);
}

void	print_octal(t_flags *data)
{
	long long		pointer;
	char		*p;
	int			len;

	check_unsigned_lenght(data, &pointer);
	p = (data->type == 'o') ? ft_itoa_base(pointer, 8, 0) : ft_itoa_base(pointer, 8, 1);
	if (data->hash)
		*p == '0' ? string_to_buff(p, data) : ft_strcharjoin('0', p) ;
	len = ft_strlen(p);
	if (data->minus && data->zero)
		data->zero = 0;
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (!data->zero && sign(data))
		add_sign_nozero(&p, data);

	if (data->width)
		calculate_width(&p, len, data);

	if (data->zero)
		add_sign_zero(&p, data);
	string_to_buff(p, data);
}

void	print_uint(t_flags *data)
{
	char	*s;
	int		len;
	long long		num;

	check_unsigned_lenght(data, &num);
	if (data->minus && data->zero)
		data->zero = 0;
	s = ft_itoa_base(num, 10, 0);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	s = ft_strdup(s);
	if (data->precision >= 0)
		s = print_precision(s, len, num, data);
	if (!data->zero && sign(data))
		add_sign_nozero(&s, data);

	if (data->width)
		calculate_width(&s, len, data);

	if (data->zero)
		add_sign_zero(&s, data);
	string_to_buff(s, data);
}



int			add_flags(t_flags *data)
{
		if (data->str[data->pos] == '-')
			data->minus = TRUE;
		else if (data->str[data->pos] == '+')
				data->plus = TRUE;
		else if (data->str[data->pos] == ' ')
				data->space = TRUE;
		else if (data->str[data->pos] == '#')
				data->hash = TRUE;
		else if (data->str[data->pos] == '0') /* maybe to delete */
				data->zero = TRUE;
		else
			return (0);
		return (1);
}

void		add_width(t_flags *data)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(T);
	if (ft_isdigit(data->str[data->pos]))
	{
		data->zero = data->str[data->pos] == '0' ? TRUE : data->zero;
		while (ft_isdigit(data->str[data->pos]))
		{
			s[i++] = data->str[data->pos++];
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

void	add_precision(t_flags *data)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(T);
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
			data->zero = data->str[data->pos] == '0' ? TRUE : data->zero;
			s[i++] = data->str[data->pos++];
		}
		data->pr_width = ft_atoi(s);
	}
}

