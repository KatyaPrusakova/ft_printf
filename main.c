/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:01:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/30 11:41:11 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char *str;
	char *a;
	char *b;
	char *c;
	char *d;
	int i;

	str = "Hello";
	i = 5;
	a = "AA";
	b ="BB";
	c ="\0CCCC";
	d = "DDDDDDD";
		/* printf("|realll %3s |%030s| |%-1s| %-2s %ss\n", a, b,c, d, a);
	 ft_printf("|simple %3s |%030s| |%-1s| %-2s %ss\n", a, b,c, d, a); */

	/*    printf("|realpri |%10.2s| |%5.1s| |%3.0s| |%6.10s|\n", str, str, str, str);
	ft_printf("|myprint |%10.2s| |%5.1s| |%3.0s| |%6.10s|\n", str, str, str, str);
 */
/*
	   printf("%.*s\n", -6 , 0);
	   printf("\n");
	ft_printf("%.*s\n", -6 , 0); */

	 printf("%5d\n", 578645);
	   printf("\n");
	ft_printf("%5d", 578645);

	/* i = printf("\n|real print %s|\n", str);
	printf("|return %d|\n", i); */
}


		// printf("|break %c|\n", data->str[data->pos]);

