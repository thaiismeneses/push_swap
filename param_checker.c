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

int	has_duplicate(t_stack *stack, int nbr)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->nbr == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

void	errors_exit(int flag, char *str)
{
	if (flag == 1)
		free(str);
	ft_printf("Error\n");
	exit(-1);
}

int	param_check(int flag, char *str)
{
	long	nbr;
	char	*to_check;
	int		i;

	i = 0;
	to_check = str;
	if (to_check[i] == '+' || to_check[i] == '-')
		to_check++;
	while (to_check[i] != '\0')
	{
		if (ft_isdigit(to_check[i]) == 0)
			errors_exit(flag, str);
		i++;
	}
	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		errors_exit(flag, str);
	return (nbr);
}