/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:20:38 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/16 16:40:00 by eprusako         ###   ########.fr       */
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


/* int		ft_snprintf(char *s, const char *format, ...)
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
	va_end(data->args);
	free(data);
	return (count);
} */

int				fd_printf(int fd, const char *format, ...)
{
	t_flags		*data;
	uintmax_t	count;

	if (!(data = (t_flags*)malloc(sizeof(t_flags))))
		return (0);
	ft_bzero(data, sizeof(t_flags));
	va_start(data->args, format);
	data->str = (char*)format;
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
