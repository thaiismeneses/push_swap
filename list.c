/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:49:54 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/25 14:49:58 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_from_list(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	lst_size(t_stack *stack)
{
	int	i;

	i = 0;
	
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	add_node(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (!(*stack))
	{
		(*stack) = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = last_from_list(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}