/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/02 14:04:19 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/* 	else if (data->precision >= 0 && !data->minus && s[0] == '-')
	{
		save_to_buff('-', data);
		s = ft_strsub(s, 1, (i-1));
		data->width = data->star_width;
		data->width -= (i-1);
		while (data->width > 0)
		{
			save_to_buff('0', data);
			data->width--;
		}
		string_to_buff(s, data);
	}
	else if (data->precision >= 0 && !data->minus)
	{
		data->width = data->star_width;
		data->width -= i;
		while (data->width > 0)
		{
			save_to_buff('0', data);
			data->width--;
		}
		string_to_buff(s, data);
	}  */
