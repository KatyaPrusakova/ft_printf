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

int			add_flags(t_flags *data)
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

void		add_width(t_flags *data)
{
	char	*s;
	int		i;

	i = 0;
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
			add_width(data);
	}
}

void		add_precision(t_flags *data)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(W);
	add_precision_help(data);
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

void		add_precision_help(t_flags *data)
{
	if (data->s[data->pos] == '.')
	{
		data->precision = TRUE;
		data->pos++;
	}
}

