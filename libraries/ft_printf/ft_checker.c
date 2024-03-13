/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:42:56 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/06 18:22:31 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(va_list args, int i, const char specifier)
{
	if (specifier == '%')
		return (ft_printchar('%'));
	else if (specifier == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_printstr(va_arg(args, const char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_printud(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_printhexa(va_arg(args, unsigned int), specifier));
	else if (specifier == 'p')
		return (ft_printpointer(va_arg(args, unsigned long long)));
	return (0);
}
