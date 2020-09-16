/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:00:30 by eprusako          #+#    #+#             */
/*   Updated: 2020/09/16 16:14:01 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdio.h>
# include "libft.h"

typedef	struct	s_flags
{
	int d;
	int s;
	int c;
}				t_flags;


void	add_flag(char **f);
void	parse_flag(char *format);
int		ft_printf(const char *format, ...);
void				*ft_memalloc(size_t size);

#endif
