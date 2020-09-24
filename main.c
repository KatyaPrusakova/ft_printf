/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:01:33 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/24 15:47:22 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char *str;
	char c;
	int i;

	str = "Hello";
	i = 5;
	c = 'A';
	ft_printf("|simple %+-c %#3c %c %0c|\n", c, c ,c, c);
	printf("|simple %+-c %#3c %c %0c|\n", c, c ,c, c);

	i = printf("\n|real print %s|\n", str);
	printf("|return %d|\n", i);
}
