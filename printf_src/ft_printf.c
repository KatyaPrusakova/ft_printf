/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:20:38 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/16 11:21:07 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	free(data);
	va_end(data->args);
	return (count);
}
