/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:20:38 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/16 16:50:14 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_data(t_flags **data)
{
	*data = (t_flags*)ft_memalloc(sizeof(t_flags));
	(*data)->d = 0;
	(*data)->c = 0;
	(*data)->s= 0;
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
