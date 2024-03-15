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

int	validating(long nbr)
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

int is_in_order(t_stack *stack)
{
	t_stack *current;

    current = stack;
    while (current != NULL && current->next != NULL)
	{
        if (current->data > current->next->data) 
		{
            return (0);
        }
        current = current->next;
    }
    return (1);
}


int	param_check(char *str)
{
	long	nbr;
	int	i;

	i = 0;
	if (ft_isalpha(str[i]) == 1)
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