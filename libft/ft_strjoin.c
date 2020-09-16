/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/17 10:15:57 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	i = 0;
	len = (ft_strlen(s1)) + (ft_strlen(s2));
	str = (char *)malloc(sizeof(char*) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (s1[i] != '\0')
	{
		str[len] = s1[i];
		i++;
		len++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[len] = s2[i];
		i++;
		len++;
	}
	str[len] = '\0';
	return (str);
}
