/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/06 19:57:24 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	reset(t_flags *data)
{
	data->width = FALSE;
	data->precision = -1;
	data->pr_width = FALSE;
	data->length = FALSE;
	data->hash = FALSE;
	data->plus = FALSE;
	data->minus = FALSE;
	data->negative = FALSE;
	data->space = FALSE;
	data->zero = FALSE;
	data->star = FALSE;
}


void		save_to_buff(char c, t_flags *data)
{
	if (data->len < 1024)
	{
		data->buff[data->len] = c;
		data->len++;
	}
}

void		print_buff(t_flags *data)
{
	write(1, data->buff, data->len);
}

void		string_to_buff(char *s, t_flags *data)
{
	while (*s)
	{
		if (data->len < 1024)
		{
			data->buff[data->len++] = *s++;
		}
		else
		{
			data->buff[data->len] = '\0';
			print_buff(data);
			ft_bzero(data->buff, 1024);
			data->len = 0;
		}
	}
}
