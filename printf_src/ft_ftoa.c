/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:18:25 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/07 19:17:29 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// str = ft_itoa_base(temp, 10, 0); /* first part before dot */

#include "ft_printf.h"

char		*ft_itoa_float(double number, t_flags *data)
{
	char			*str;
	char			*pr;
	// char			number_to_change;
	uintmax_t		temp;
	int				pr_w;
	double			round_up;
	int				real_number;
	int				pr_width;

	pr_w = data->pr_width;
	pr_width = data->pr_width;
	temp = number; /* number 99 */
	pr = ft_strnew(pr_width);
	str = ft_strcat(ft_itoa_base((uintmax_t)temp, 10, 0), ".");
	number = number - temp;
	while (pr_w--)
	{
		number *= 10;
	}
	real_number = number;
	round_up = number;
	number *= 10;
	if (number > 4)
		real_number++;
	while(pr_width > 0)
	{
		pr_width--;
		pr[pr_width] = (int)real_number % 10 + '0';
		real_number /= 10;
	}
	// printf("temp is %s |%s| |%c|\n", str, pr, number_to_change);
	return (ft_strcat(str,pr));
}
/*

number_to_change = (int)number % 10 + '0';
	if (number_to_change > '4' && number_to_change <= '9' )
	{
		if (number_to_change == '9')
			temp += 0.5;
		else
			number_to_change++;
	} */
