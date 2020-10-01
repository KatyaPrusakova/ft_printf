/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:01:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/01 19:45:41 by eprusako         ###   ########.fr       */
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
printf("%030.3d|", 8375);
	   printf("\n");
	ft_printf("%030.3d|\n", 8375);
 printf("\n");
	printf("%08.3d|", 8375);
	   printf("\n");
	ft_printf("%08.3d|\n", 8375);
 printf("\n");

 	printf("%0-8.3d|", 8375);
	   printf("\n");
	ft_printf("%0-8.3d|\n", 8375);
 printf("\n"); */
/*
 	printf("%7d", -14);
	   printf("\n");
	ft_printf("%7d\n", -14);
 */
 printf("\n");
	printf("%07d", -14);
	   printf("\n");
	ft_printf("%07d", -14);


 printf("\n");
	printf("%d|", -2375);
	   printf("\n");
	ft_printf("%d|\n\n", -2375);
 printf("\n");
	 printf("%.*d", -1, 12345);
	   printf("\n");
	ft_printf("%.*d\n", -1, 12345);

	/* i = printf("\n|real print %s|\n", str);
	printf("|return %d|\n", i); */
}


		// printf("|break %c|\n", data->str[data->pos]);

