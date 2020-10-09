/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:20:38 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/09 19:46:25 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_data(t_flags *data)
{
	ft_bzero(data, sizeof(t_flags));
}

int		ft_printf(const char *format, ...)
{

	t_flags		*data;
	uintmax_t	count;

	if (!(data = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	ft_bzero(data, sizeof(t_flags));
	va_start(data->args, format);
	data->str = (char*)format;
	count = parse_menu(data);
	// printf("1. %s\n", va_arg(data->args,char*));

	va_end (data->args) ;
	return (count);
}
