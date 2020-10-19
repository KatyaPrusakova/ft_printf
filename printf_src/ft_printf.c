/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:20:38 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/19 10:08:23 by eprusako         ###   ########.fr       */
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
	data->option = 0;
	count = parse_menu(data);
	va_end(data->args);
	free(data);
	return (count);
}


char		*ft_sprintf(char *s, const char *format, ...)
{
	t_flags		*data;
	uintmax_t	count;

	if (!(data = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	ft_bzero(data, sizeof(t_flags));
	va_start(data->args, format);
	data->str = (char*)format;
	data->option = 1;
	count = parse_menu(data);
	s = data->buff;
	va_end(data->args);
	free(data);
	return (s);
}

int				fd_printf(int fd, const char *format, ...)
{
	t_flags		*data;
	uintmax_t	count;

	if (!(data = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	ft_bzero(data, sizeof(t_flags));
	va_start(data->args, format);
	data->str = (char*)format;
	data->option = 2;
	count = parse_menu( data);
	va_end(data->args);
	write(fd, data->buff, data->len);
	free(data);
	return (count);
}

/*
void		ft_n(int i)
{
	char c;

	c = '\n';
	i = c;
	printf("%c\n", (char)i);
}
 */
