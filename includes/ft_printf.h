/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:00:30 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/20 16:46:22 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define SPECIFIERS	"ncspdioOuxXf%"
# define LENGTH		"hlLzj"
# define FLAGS		"#0-+ .*0123456789hlLzj"
# define CASE		"#0-+ .*0123456789hlLzjcCsSnpdioOuUxXfF"
# define OX			"0x"
# define BIGOX		"0X"

# define SIZE 1024
# define TRUE 1
# define FALSE 0
# define L	1
# define LL	2
# define BL	3
# define H	4
# define HH	5
# define J	6
# define Z	7
# define W	8

typedef	struct	s_flags
{
	va_list	args;
	int		option;
	char	*s;
	char	buff[SIZE];
	int		len;
	int		pos;
	int		printed;
	char	type;
	int		width;
	int		w_width;
	int		star;
	int		precision;
	int		p_w;
	int		length;
	int		hash;
	int		plus;
	int		minus;
	int		space;
	int		zero;
	int		negative;
}				t_flags;

int			scan_type(t_flags *data);

void		switch_type(t_flags *data);
int			parse_menu(t_flags *data);
int			add_flags(t_flags *data);

void		add_precision(t_flags *data);
void		add_precision_help(t_flags *data);
void		add_width(t_flags *data);

void		add_lenght(t_flags *data);
void		check_lenght(t_flags *data, long long *number);
void		check_unsigned_lenght(t_flags *data, long long *n);

char		*print_width(char *s, char *temp, t_flags *data);
char		*print_width_minus(char *s, char *temp, t_flags *data);
char		*print_precision(char *s, int len, int num, t_flags *data);
int			print_decimal(t_flags *data);

int			sign(t_flags *data);
void		add_sign(char **s, t_flags *data);
void		calculate_width(char **s, int len, t_flags *data);

int			ft_printf(const char *format, ...);
char		*ft_sprintf(char *s, const char *format, ...);
int			fd_printf(int fd, const char *form, ...);

void		print_percent(t_flags *data);
void		print_pointer(t_flags *data);
void		print_char(t_flags *data);
void		print_string(t_flags *data);
void		print_binary(t_flags *data);

void		print_decimal_help(t_flags *data, long long *number);
void		print_hash(char **p, t_flags *data);
void		print_hex(t_flags *data);
void		print_octal(t_flags *data);
void		print_uint(t_flags *data);

void		print_width_to_buf(char width, t_flags *data);
int			help_to_print_string(int i, char *s, t_flags *data);
void		string_to_buff(char *s, t_flags *data);
int			print_buff(t_flags *data);
void		save_to_buff(char c, t_flags *data);
void		reset(t_flags *data);

char		*ft_ftoa(long double f, int precision, int hash);
void		print_float(t_flags *data);
char		*check_float(t_flags *data, long double *number);

#endif
