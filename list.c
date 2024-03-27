/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:49:54 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 11:57:39 by thfranco         ###   ########.fr       */
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

t_stack	*find_node_min(t_stack *stack)
{
	t_stack		*min_node;
	int			min_value;
	
	if (!stack)
		return (NULL);
	min_value = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min_value)
		{
			min_value = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_node_max(t_stack *stack)
{
	t_stack		*max_node;
	int			max_value;

	if (!stack)
		return (NULL);
	max_value = INT_MIN;
	while (stack)
	{
		if (stack->nbr < max_value)
		{
			max_value = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	add_node(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
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