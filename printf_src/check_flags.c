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
	long long		pointer;
	char			*p;
	int				len;

	if (data->zero && data->pr_width)
		data->zero = 0;
	check_unsigned_lenght(data, &pointer);
	if (!(p = (data->type == 'x') ? ft_itoa_base(pointer, 2, 0) : ft_itoa_base(pointer, 2, 0)))
		p = ft_strdup("null");
	len = ft_strlen(p);
	if (*p == '0')
		data->hash = 0;
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (data->hash > 0)
		print_hash(&p, data);
	if (data->width)
		calculate_width(&p, len, data);
	string_to_buff(p, data);
	free(p);
}

void		print_hash(char **p, t_flags *data)
{
	if (data->hash && data->width && data->zero)
	{
		if (data->pr_width)
			*p = (data->type == 'x') ? ft_strjoinfree(OX, *p, 0, 1) : ft_strjoinfree(BIGOX, *p, 0, 1);
		else
			data->type == 'x' ? string_to_buff(OX, data) : string_to_buff(BIGOX, data) ;
		data->width -= 2;
	}
	if (data->hash && !data->zero)
	{
		*p = (data->type == 'x') ? ft_strjoinfree(OX, *p, 0, 1) : ft_strjoinfree(BIGOX, *p, 0, 1);
		if (data->width > 0)
			data->width -= 2;
	}
}

void	print_hex(t_flags *data)
{
	long long		pointer;
	char			*p;
	int				len;

	if (data->zero && data->pr_width)
		data->zero = 0;
	check_unsigned_lenght(data, &pointer);
	if (!(p = (data->type == 'x') ? ft_itoa_base(pointer, 16, 0) : ft_itoa_base(pointer, 16, 1)))
		p = ft_strdup("null");
	len = ft_strlen(p);
	if (*p == '0')
		data->hash = 0;
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (data->hash > 0)
		print_hash(&p, data);
	if (data->width)
		calculate_width(&p, len, data);
	string_to_buff(p, data);
	free(p);
}

void	print_octal(t_flags *data)
{
	long long		pointer;
	char			*p;
	int				len;

	check_unsigned_lenght(data, &pointer);
	p = (data->type == 'o') ? ft_itoa_base(pointer, 8, 0) : ft_itoa_base(pointer, 8, 1) ;
	if (!p)
		p = ft_strdup("null");
	if (data->hash)
	{
		if (p[0] == '0')
			string_to_buff(p, data);
		else
			p = ft_strcharjoin('0', p);
	}
	len = ft_strlen(p);
	if (data->precision >= 0)
		p = print_precision(p, len, pointer, data);
	if (!data->zero && sign(data))
		add_sign(&p, data);
	if (data->width)
		calculate_width(&p, len, data);
	if (data->zero)
		add_sign(&p, data);
	string_to_buff(p, data);
	free(p);
}

void	print_uint(t_flags *data)
{
	char			*s;
	int				len;
	long long		num;

	check_unsigned_lenght(data, &num);
	if (data->zero && data->pr_width)
		data->zero = 0;
	s = ft_itoa_base(num, 10, 0);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (data->precision >= 0)
		s = print_precision(s, len, num, data);
	if (data->width)
		calculate_width(&s, len, data);
	string_to_buff(s, data);
	free(s);
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
	else if (data->str[data->pos] == '0')
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
	free(s);
	if (data->str[data->pos] == '*')
	{
		data->star = TRUE;
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus = TRUE;
			data->width = -data->width;
		}
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
			free(s);
			return ;
		}
		while (ft_isdigit(data->str[data->pos]))
		{
			data->zero = data->str[data->pos] == '0' ? TRUE : data->zero;
			s[i++] = data->str[data->pos++];
		}
		data->pr_width = ft_atoi(s);
	}
	free(s);
}

