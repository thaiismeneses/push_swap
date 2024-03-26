/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:24:05 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/20 13:22:20 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
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

int	main(int argc, char **argv)
{
	int			i;
	int			nbr;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		exit (-1);
	if (argc == 2)
	{
		argv = ft_split(argv[i], ' ');
		i--;
	}
	if (argc >= 2)
	{
		while (argv[i])
		{
			nbr = param_check(argc == 2, argv[i]);
			if ((has_duplicate(stack_a, nbr)) == 0)
				add_node(&stack_a, nbr);
			else
			{
				free_list(stack_a);
				errors_exit(0, argv[i]);
			}
			i++;
		}
		if (is_in_order(stack_a))
		{
			free_list(stack_a);
			exit (-1);
		}
		ft_printf("Stack A:\n");
		print_list(stack_a);
		sort(&stack_a, &stack_b);
		ft_printf("Stack A:\n");
		print_list(stack_a);
	 } 
	free_list(stack_a);
	return(0);
}