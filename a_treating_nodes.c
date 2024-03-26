/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_treating_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:28:12 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/26 13:02:07 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack **stack)
{
	int i;
	int median;

	i = 0;
	if (!(*stack))
		return ;
	median = lst_size((*stack)) / 2;
	while ((*stack))
	{
		(*stack)->index = i;
		if (i <= median)
			(*stack)->above_median = true;
		else
			(*stack)->above_median = false;
		(*stack) = (*stack)->next;
		++i;
	}
}

void	set_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	int	best_match_index;

	while ((*stack_a))
	{
		best_match_index = INT_MIN;
		current_b = (*stack_b);
		while (current_b)
		{
			if(current_b->nbr < (*stack_a)->nbr 
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			(*stack_a)->target_node = find_node_max(stack_b);
		else
			(*stack_a)->target_node = target_node;
		(*stack_a) = (*stack_a)->next;
	}
}

void	cost_analysis_a(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int len_b;

	len_a = lst_size((*stack_a));
	len_b = lst_size((*stack_b));
	while ((*stack_a))
	{
		(*stack_a)->push_cost = (*stack_a)->index;
		if (!(*stack_a)->above_median)
			(*stack_a)->push_cost = len_a - ((*stack_a)->index);
		if ((*stack_a)->target_node->above_median)
			(*stack_a)->push_cost += (*stack_a)->target_node->index;
		else
			(*stack_a)->push_cost += len_b - ((*stack_a)->target_node->index);
		(*stack_a) = (*stack_a)->next;
	}

}

void	set_cheapest(t_stack *stack)
{
	int	cheapest_value;
	t_stack	*cheapest_node;

	cheapest_value = INT_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->lowest = true;
}

void	start_nodes_a(t_stack **stack_a, t_stack **stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(*stack_a);
}