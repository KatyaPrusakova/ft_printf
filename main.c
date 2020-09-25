/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:01:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/25 14:37:16 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char *str;
	char a;
	char b;
	char c;
	char d;
	int i;

	str = "Hello";
	i = 5;
	a = 'A';
	b = 'B';
	c = 'C';
	d = 'D';
	ft_printf("|simple %+-c\n %#3c\n %.c\n %0c %000c\n", a, b ,c, d, a);
	printf("|real %+-c\n %#3c\n %.c\n %0c %000c\n", a, b ,c, d, a);

	i = printf("\n|real print %s|\n", str);
	printf("|return %d|\n", i);
}


