/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:00:30 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/21 14:34:43 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

/*
** ------ FLAGS / MODIFIERS / CONVERSION VARIABLES ------
*/

# define SPECIFIERS	"ncspdioOuxXbBf%"
# define FLAGS		"#0-+ .*0123456789hlLzj"
# define CASE		"#0-+ .*0123456789hlLzjcCsSpPdDiIoOuUxXfFbBn"
# define SIZE		1024
# define TRUE		1
# define FALSE		0
# define L			1
# define LL			2
# define BL			3
# define H			4
# define HH			5
# define J			6
# define Z			7
# define W			8

typedef	struct	s_flags
{
	va_list		args;
	int			option;
	char		*s;
	char		buff[SIZE];
	int			len;
	int			pos;
	int			printed;
	char		type;
	int			width;
	int			w_width;
	int			star;
	int			precision;
	int			p_w;
	int			length;
	int			hash;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			negative;
}				t_flags;

/*
** ------ FT_PRINTF.C ------
*/

int				ft_printf(const char *format, ...);
char			*ft_sprintf(char *s, const char *format, ...);
int				fd_printf(int fd, const char *form, ...);

/*
** ------ PARSE_MENU.C ------
*/

int				parse_menu(t_flags *data);
int				scan_type(t_flags *data);
void			switch_type(t_flags *data);
void			check_lenght(t_flags *data, long long *number);
void			check_unsigned_lenght(t_flags *data, long long *n);

/*
** ------ PARSE_FLAGS.C ------
*/
int				check_flags(t_flags *data);
void			check_width(int i, t_flags *data);
void			check_precision(int i, t_flags *data);
void			check_precision_help(t_flags *data);
void			check_lenght_modifier(t_flags *data);

/*
** ------ PRINT_WIDTH_HASH.C ------
*/
void			calculate_width(char **s, int len, t_flags *data);
char			*print_width(char *s, char *temp, t_flags *data);
char			*print_width_minus(char *s, char *temp, t_flags *data);
void			print_hash(char **p, t_flags *data);
int				print_hash_octal(char **p, t_flags *data);

/*
** ------ PRINT_DI.C ------
*/
int				sign(t_flags *data);
void			add_sign(char **s, t_flags *data);
char			*print_precision(char *s, int len, int num, t_flags *data);
void			print_decimal_help(t_flags *data, long long *number);
int				print_decimal(t_flags *data);

/*
** ------ PRINT_CSP.C ------
*/

void			print_pointer(t_flags *data);
void			print_char(t_flags *data);
void			print_string(t_flags *data);
int				print_string_help(int i, char *s, t_flags *data);
void			print_string_with_presicion(int len, char *s, t_flags *data);

/*
** ------ PRINT_UOXB.C ------
*/

void			print_binary(t_flags *data);
void			print_hex(t_flags *data);
void			print_octal(t_flags *data);
void			print_uint(t_flags *data);
void			print_percent(t_flags *data);

/*
** ------ PRINT_f.C ------
*/

char			*ft_ftoa(long double f, int precision, int hash);
void			print_float(t_flags *data);
char			*check_float(t_flags *data, long double *number);

/*
** ------ PRINT_BUFF.C ------
*/

void			width_to_buf(char width, t_flags *data);
void			string_to_buff(char *s, t_flags *data);
int				print_buff(t_flags *data);
void			save_to_buff(char c, t_flags *data);
void			reset(t_flags *data);

#endif
