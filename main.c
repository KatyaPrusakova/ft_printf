/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:01:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/15 12:13:33 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	init_data(t_flags **data)
{
	*data = (t_flags*)ft_memalloc(sizeof(t_flags));
	(*data)->d = 0;
	(*data)->c = 0;
	(*data)->s= 0;
}

void	add_flag(char **f)
{
	t_flags data;

	printf("add_flag %s\n", *f);
}

void	parse_flag(char *format)
{
	while (format)
	{
		if (*format == '%')
			add_flag(&format);
		format++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		a;

	va_start(args, format);
//	vprintf(format, args) ;
	str = va_arg(args,char*);
	printf("1. %s\n", str);
	a = va_arg(args,int);
	printf("2. %d\n", a);
	printf("---%s---", format);
	va_end (args) ;
	return (1);
}

int		main(void)
{
	char *str;
	int i;

	str = "Hello";
	i = 5;
	ft_printf("|simple %s %d|", str, i);
}
