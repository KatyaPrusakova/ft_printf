/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/21 12:04:31 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_flags(t_flags *data)
{
	if (data->s[data->pos] == '-')
		data->minus = TRUE;
	else if (data->s[data->pos] == '+')
		data->plus = TRUE;
	else if (data->s[data->pos] == ' ')
		data->space = TRUE;
	else if (data->s[data->pos] == '#')
		data->hash = TRUE;
	else if (data->s[data->pos] == '0')
		data->zero = TRUE;
	else
		return (0);
	return (1);
}

void		check_width(int i, t_flags *data)
{
	char	*s;

	s = ft_strnew(W);
	if (ft_isdigit(data->s[data->pos]))
	{
		data->zero = data->s[data->pos] == '0' ? TRUE : data->zero;
		while (ft_isdigit(data->s[data->pos]))
			s[i++] = data->s[data->pos++];
		data->width = ft_atoi(s);
	}
	free(s);
	if (data->s[data->pos] == '*')
	{
		data->star = TRUE;
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus = TRUE;
			data->width = -data->width;
		}
		data->pos++;
		if (ft_isdigit(data->s[data->pos]))
			check_width(0, data);
	}
}

void		check_precision(int i, t_flags *data)
{
	char	*s;

	s = ft_strnew(W);
	check_precision_help(data);
	if (data->s[data->pos] == '*')
	{
		data->star = TRUE;
		data->p_w = va_arg(data->args, int);
		data->pos++;
		free(s);
		return ;
	}
	while (ft_isdigit(data->s[data->pos]))
	{
		if (!ft_strrchr(&data->s[data->pos], 'f'))
			data->zero = (data->s[data->pos] == '0') ? TRUE : data->zero;
		s[i++] = data->s[data->pos++];
	}
	data->p_w = ft_atoi(s);
	if (data->star && data->p_w < 0)
	{
		data->p_w = 0;
		data->precision = -1;
	}
	free(s);
}

void		check_precision_help(t_flags *data)
{
	if (data->s[data->pos] == '.')
	{
		data->precision = TRUE;
		data->pos++;
	}
}

void		check_lenght_modifier(t_flags *data)
{
	if (data->s[data->pos] == 'h')
		if (data->s[data->pos + 1] == 'h')
			data->length = HH;
		else
			data->length = H;
	else if (data->s[data->pos] == 'l')
		if (data->s[data->pos + 1] == 'l')
			data->length = LL;
		else
			data->length = L;
	else if (data->s[data->pos] == 'L')
		data->length = BL;
	else if (data->s[data->pos] == 'j')
		data->length = J;
	else if (data->s[data->pos] == 'z')
		data->length = Z;
	while (ft_strchr("hlLzj", data->s[data->pos]))
		data->pos++;
}
