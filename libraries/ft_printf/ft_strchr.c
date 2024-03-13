/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:50:48 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/03 22:06:17 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)s;
	while (src[i] != c)
	{
		if (src[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)src + i);
}
