/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/14 13:27:13 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcharjoin(int c, const char *s)
{
	size_t			len;
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	len = (1 + ft_strlen(s));
	str = (char *)malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	j = 1;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[len] = '\0';
/* 	free((char*)s); */
	return (str);
}
