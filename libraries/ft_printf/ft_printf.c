/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:15:48 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/06 16:31:17 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		str_length;
	int		i;

	i = 0;
	str_length = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			str_length += ft_checker(args, i, str[i + 1]);
			i++;
		}
		else
			str_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (str_length);
}
