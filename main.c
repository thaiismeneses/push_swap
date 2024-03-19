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

void	free_list(t_stack *stack)
{
	t_stack	*current = stack;
	while (current != NULL)
	{
		t_stack *temp = current;
		current = current->next;
		free(temp);
	}
}

void	print_list(t_stack *stack)
{
	t_stack	*current = stack;
	while (current != NULL)
	{
		ft_printf("swap: %d\n", current->data);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int nbr;
	t_stack	*stack_a = NULL;
	//t_stack	*stack_b = NULL;

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
			{
				t_stack	*new_node = (t_stack *)malloc(sizeof(t_stack));
				new_node->data = nbr;
				new_node->next = NULL;
				ft_lstadd_back((t_list **)&stack_a, (t_list *)new_node);
			}
			else
			{
				//ft_printf("has duplicated");
				ft_printf("Error\n");
				exit(-1);
			}
			i++;
		}
		if(is_in_order(stack_a) == 1)
		{
			//ft_printf("Error\n");
			//ft_printf(" is in order\n");
			exit(-1);
		}
		//swap(&stack_a);
		/*
		push(&stack_a, &stack_b);
		ft_printf("Stack A: \n");
		print_list(stack_a);
		ft_printf("Stack B: \n");
		print_list(stack_b);*/
		//reverse_rotate(&stack_a);
		//print_list(stack_a);
	}
	free_list(stack_a);
	free(argv);
	//free_list(stack_b);
	return(0);
}