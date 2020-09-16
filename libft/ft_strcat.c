/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:10:06 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/30 09:35:41 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dst, const char *src)
{
	size_t		i;
	size_t		ii;

	i = 0;
	ii = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	while (src[ii] != '\0')
	{
		dst[i] = src[ii];
		i++;
		ii++;
	}
	dst[i] = '\0';
	return (dst);
}
