/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:13:53 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/07 11:26:06 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointerlen(unsigned long long pointer)
{
	int	length;

	length = 0;
	while (pointer != 0)
	{
		pointer = pointer / 16;
		length++;
	}
	return (length);
}

static int	turnhexa(unsigned long long pointer)
{
	if (pointer >= 16)
	{
		turnhexa(pointer / 16);
		turnhexa(pointer % 16);
	}
	else
	{
		if (pointer <= 9)
			ft_printchar(pointer + '0');
		else
			ft_printchar(pointer - 10 + 'a');
	}
	return (pointerlen(pointer));
}

int	ft_printpointer(unsigned long long pointer)
{
	int	len;

	len = 0;
	if (pointer == 0)
	{
		len += (ft_printstr("(nil)"));
		return (len);
	}
	len = write (1, "0x", 2);
	len += pointerlen(pointer);
	turnhexa(pointer);
	return (len);
}
