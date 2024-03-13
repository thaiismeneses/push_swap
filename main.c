/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:24:05 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/13 14:10:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validating(long nbr)
{
	if (nbr > 2147483646 || nbr < -2147483646)
		return (-1);
	return (0);
}

int	param_check(char *str)
{
	long	nbr;
	int	i;
	i = 0;
	if (str[i] == '-')
		i++;
	//ft_putnbr_fd(nbr, 1);
	if (ft_isdigit(str[i]) == 0)
	{
		ft_printf("not numeric\n");
		ft_printf("Error\n");
		exit(-1);
	}
	nbr = ft_atoi(str);
	ft_printf("%d\n", nbr);	
	if (validating(nbr) == -1)
		ft_printf("Error\n");
	return (nbr);
}


int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit (-1);
	else
	{
		while (argv[i])
		{
			param_check(argv[i]);
			i++;
		}
		
	}
	return(0);
}
