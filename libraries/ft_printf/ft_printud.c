/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:53 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/06 15:32:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_length(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_printchar(n % 10 + '0');
	}
	else
		ft_printchar(n + '0');
}

int	ft_printud(unsigned int n)
{
	int	i;

	if (n == 0)
	{
		i = ft_printchar(48);
		return (i);
	}
	ft_putnbr(n);
	i = nb_length(n);
	return (i);
}
