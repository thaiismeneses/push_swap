/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:44 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/28 15:39:15 by thfranco         ###   ########.fr       */
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

void	errors_exit(int flag, char **str, t_stack **stack)
{
	int	i;

	i = 0;
	if (flag)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	free_list(stack);
	ft_printf("Error\n");
	exit(-1);
}

void	param_check(int flag, char **argv, t_stack **stack)
{
	long	nbr;
	char	*to_check;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		to_check = argv[i];
		if (to_check[j] == '+' || to_check[j] == '-')
			to_check++;
		while (to_check[j] != '\0')
		{
			if (ft_isdigit(to_check[j]) == 0)
				errors_exit(flag, argv, stack);
			j++;
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			errors_exit(flag, argv, stack);
		i++;
	}
}
