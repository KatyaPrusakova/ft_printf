/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/30 18:27:23 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/* 	else if (data->precision >= 0 && !data->minus && s[0] == '-')
	{
		save_to_buff('-', data);
		s = ft_strsub(s, 1, (i-1));
		data->width = data->pr_width;
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
		data->width = data->pr_width;
		data->width -= i;
		while (data->width > 0)
		{
			save_to_buff('0', data);
			data->width--;
		}
		string_to_buff(s, data);
	}  */
