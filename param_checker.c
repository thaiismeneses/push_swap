/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:44 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/15 13:49:47 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validating_int(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (-1);
	return (0);
}

int	has_duplicate(t_stack *stack, int nbr)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->data == nbr)
			return (1);	
		current = current->next;	
	}
	return (0);
}

int	transform_input(char *str)
{
	long	nbr;

	nbr = ft_atoi(str);
	ft_printf("%d\n", nbr);	
	return (nbr);
}


int	param_check(char *str)
{
	long	nbr;
	char	*to_check;
	int	i;

	i = 0;
	to_check = str;
	if (to_check[i] == '+' || to_check[i] == '-')
		to_check++;
	if (ft_isdigit(to_check[i]) == 0)
	{
		ft_printf("is not digit");
		ft_printf("Error\n");
		exit(-1);
	}
	nbr = transform_input(str);
	if (validating_int(nbr) == -1)
	{
		ft_printf("int max or min");
		ft_printf("Error\n");
	}
	return (nbr);
}