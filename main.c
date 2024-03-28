/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:24:05 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 12:13:33 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	print_list(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->nbr);
		current = current->next;
	}
}

void	handle_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		nbr = param_check(argc == 2, argv[i]);
		if ((has_duplicate(*stack_a, nbr)) == 0)
			add_node(stack_a, nbr);
		else
		{
			free_list(stack_a);
			errors_exit(0, argv[i]);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit (-1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_printf("argc: %d\n", argc);
	handle_arguments(argc, argv, &stack_a);
	if (!is_in_order(stack_a))
	{
		if (lst_size(stack_a) == 2)
			sa(&stack_a, false);
		else if (lst_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_more_than_three(&stack_a, &stack_b);
	}
	free(argv);
	free_list(&stack_a);
	return (0);
}
