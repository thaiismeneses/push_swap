/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:49 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 12:03:28 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		ft_printf("ss\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!print)
		ft_printf("rrr\n");
}

void	rotate_both(t_stack **stack_a,
			t_stack **stack_b,
			t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->target_node
		&& (*stack_a) != cheapest_node)
		rr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rev_rotate_both(t_stack **stack_a,
			t_stack **stack_b,
			t_stack *cheapest_node)
{
	while ((*stack_b) != cheapest_node->target_node
		&& (*stack_a) != cheapest_node)
		rrr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}
