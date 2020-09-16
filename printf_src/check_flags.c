/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:05 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/16 16:19:43 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flag(char **f)
{
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
