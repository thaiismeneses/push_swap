/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:44 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 11:54:42 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

t_bool	is_in_order(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_node_max(*stack);
	if (biggest_node == *stack)
		ra(stack, false);
	else if ((*stack)->next == biggest_node)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}

void	sort_more_than_three(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = lst_size(*stack_a);
	if (len_a-- > 3 && !is_in_order(*stack_a))
		pb(stack_a, stack_b, false);
	if (len_a-- > 3 && !is_in_order(*stack_a))
		pb(stack_a, stack_b, false);
	while (len_a-- > 3 && !is_in_order(*stack_a))
	{
		start_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		start_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
