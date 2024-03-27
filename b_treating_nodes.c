/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_treating_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:03:01 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 11:50:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack	*stack_a, t_stack *stack_b)
{
	t_stack		*current_a;
	t_stack		*target_node;
	int			best_match_index;

	while (stack_b)
	{
		best_match_index = INT_MIN;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->nbr < stack_b->nbr
				&& current_a->nbr > best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MIN)
			stack_b->target_node = find_node_max(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	start_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
