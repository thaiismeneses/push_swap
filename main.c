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
int	has_duplicate(t_stack *stack_a, int nbr)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		if (current->data == nbr)
			return (1);	
		current = current->next;	
	}
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

void	free_list(t_stack *stack_a)
{
	t_stack	*current = stack_a;
	while (current != NULL)
	{
		t_stack *temp = current;
		current = current->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int nbr;
	t_stack	*stack_a = NULL;
	//t_stack	*stack_b;

	i = 1;
	if (argc < 2)
		exit (-1);
	else
	{
		while (argv[i])
		{
			nbr = param_check(argv[i]);
			if ((has_duplicate(stack_a, nbr)) == 0)
			{
				t_stack	*new_node = (t_stack *)malloc(sizeof(t_stack));
				new_node->data = nbr;
				new_node->next = NULL;
				ft_lstadd_back((t_list **)&stack_a, (t_list *)new_node);
			}
			else
			{
				ft_printf("Error\n");
				exit(-1);
			}
			i++;
		}
	}
	free_list(stack_a);
	return(0);
}