/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:00:30 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/28 16:04:46 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdio.h>
# include "libft.h"

# define SPECIFIERS	"cspdiouxXf%"
# define FLAGS		"#0-+ .*0123456789hlLz"
# define CASE		"#0-+ .*0123456789hlLzcspdiouxXf" /* % separate case */

# define SIZE 1000
# define TRUE 1
# define FALSE 0


typedef	struct	s_print
{
	char	type;
	int		width;
	int		precision;
	int		lenght;

	int		hash;
	int		plus;
	int		minus;
	int		space;
	int		zero;

}				t_print;

typedef	struct	s_flags
{
	va_list	args;

	char	*str;
	char	buff[SIZE];
	int		len;
	int		pos;
	int		printed;
	int		format_size;

	char	type;
	int		width;
	int		precision;
	int		pr_width;
	int		lenght;

	int		hash;
	int		plus;
	int		minus;
	int		space;
	int		zero;
}				t_flags;



void	parse_menu(t_flags *data);
int		add_flags(t_flags *data);
// void	parse_flags(t_flags *data);
int		ft_printf(const char *format, ...);


#endif

	// int c; // (character)
	// int s; // (string)
	// int p; // (address)
	// int d; // (digit)
	// int i; // (integer)
	// int o; // (digit in octal)
	// int u; // (unsigned integer)
	// int x; // (hexadecimal in lowercase)
	// int X; // (hexadecimal in upper case)
	// int f; // (float)

    /*
    '#'(hash) - For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.

    '0'(zero) - When the 'width' option is specified, prepends zeros for numeric types.
    For example, printf("%2X",3) produces ' 3', while printf("%04X",3) produces '0003'.

    '-'(minus) - Left-align the output of this placeholder. (The default is to right-align the output.)

    '+'(plus) - Prepends a plus for positive signed-numeric types.

    ' '(space) - Prepends a space for positive signed-numeric types.This flag is ignored if the + flag exists.
    */

    /*
    'l' - For integer types, causes ft_printf to expect a long-sized integer argument.
    'L' - For floating point types, causes ft_printf to expect a long double argument.
    'hh' - For integer types, causes ft_printf to expect an int-sized integer argument which was promoted from a char.
    'h' - For integer types, causes ft_printf to expect an int-sized integer argument which was promoted from a short.
    'l' - For integer types, causes ft_printf to expect a long-sized integer argument.
    'll' - For integer types, causes ft_printf to expect a long long-sized integer argument.
     */
