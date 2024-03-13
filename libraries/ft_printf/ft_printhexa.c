/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:37:09 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/06 17:03:31 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexalen(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n = n / 16;
		length++;
	}
	return (length);
}

static void	turnhexa(unsigned int n, const char specifier)
{
	if (n >= 16)
	{
		turnhexa(n / 16, specifier);
		turnhexa(n % 16, specifier);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + '0');
		else
		{
			if (specifier == 'x')
				ft_printchar(n - 10 + 'a');
			if (specifier == 'X')
				ft_printchar(n - 10 + 'A');
		}
	}
}

int	ft_printhexa(unsigned int n, const char specifier)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_printchar(48);
		return (len);
	}
	len += hexalen(n);
	turnhexa(n, specifier);
	return (len);
}
