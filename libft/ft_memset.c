/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:10:06 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/30 09:35:49 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *ptr, int c, size_t len)
{
	char	*dest;

	dest = (char *)ptr;
	while (len > 0)
	{
		dest[len - 1] = c;
		len--;
	}
	return (ptr);
}
