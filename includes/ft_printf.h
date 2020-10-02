/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:00:30 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/02 20:17:21 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdio.h>
# include "libft.h"

# define SPECIFIERS	"cspdiouxXf%"
# define LENGTH		"hlLzjt"
# define FLAGS		"#0-+ .*0123456789hlLzjt"
# define CASE		"#0-+ .*0123456789hlLzjtcspdiouxXf" /* % separate case */

# define SIZE 2000
# define TRUE 1
# define FALSE 0
# define L	1
# define LL	2
# define BL	3
# define H	4
# define HH	5
# define J	6
# define Z	7
# define T	8

// lenght
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
	int		w_width;
	int		star;
	int		precision;
	int		pr_width;
	int		length;

	int		hash;
	int		plus;
	int		minus;
	int		space;
	int		zero;
	int		negative;
}				t_flags;



void	parse_menu(t_flags *data);
int		add_flags(t_flags *data);
// void	parse_flags(t_flags *data);
int		ft_printf(const char *format, ...);
void	print_percent(t_flags *data);
void	print_pointer(t_flags *data);
void	print_char(t_flags *data);
void	print_string(t_flags *data);

void		string_to_buff(char *s, t_flags *data);
void		print_buff(t_flags *data);
void		save_to_buff(char c, t_flags *data);

void	reset(t_flags *data);

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
    'L' - For integer types, causes ft_printf to expect a long-sized integer argument.
    'LL' - For floating point types, causes ft_printf to expect a long double argument.
    'hh' - For integer types, causes ft_printf to expect an int-sized integer argument which was promoted from a char.
    'h' - For integer types, causes ft_printf to expect an int-sized integer argument which was promoted from a short.
    'l' - For integer types, causes ft_printf to expect a long-sized integer argument.
    'll' - For integer types, causes ft_printf to expect a long long-sized integer argument.
     */
