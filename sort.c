/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:07:38 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/26 13:07:40 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_id)
{
	while(*stack != top_node)
	{
		if (stack_id  == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_id == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else	
				rrb(stack, false);
		}
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->lowest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!cheapest_node->above_median && cheapest_node->target_node->above_median)
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_a, stack_b, false);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a,(*stack_b)->target_node, 'a');
	pb(stack_a, stack_b, false);
}

void	min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->nbr != find_node_min(stack_a)->nbr)
	{
		if (find_node_min(stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}