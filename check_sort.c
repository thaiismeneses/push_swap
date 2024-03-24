/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:44 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/20 11:25:33 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_order(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL && current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	find_min(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current;
	t_stack	*min_node;
	t_stack *prev_min;
	//t_stack	*preview;
	int	min_value;

	min_value = (*stack_a)->data;
	min_node = (*stack_a);
	current = (*stack_a);
	prev_min = NULL;
	//preview = NULL;
	while (current != NULL)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
			min_node = current;
			prev_min = (*stack_a);
		}
		current = current->next;
	}
	if(min_node == (*stack_a))
		return ;
	prev_min->next = min_node->next;
	pb(&min_node, stack_b);
}

/*void	update_stack(t_stack **stack, int to_push)
{
	//t_stack	*current;

	if (*stack == to_push)
	{
		(*stack) = (*stack)->next;
	}
	else
	{
		//current = (*stack_a);
		while ((*stack) != NULL && (*stack)->next != to_push)
			(*stack) = (*stack)->next;
		if ((*stack) != NULL)
			current->next = to_push->next;
	}
	print_list(current);

}*/


void	sort_three(t_stack **stack)
 {
	if (((*stack)->data < (*stack)->next->data) &&
		((*stack)->next->data > (*stack)->next->next->data))
		rra(stack);
	else if (((*stack)->data > (*stack)->next->data) &&
		((*stack)->data > (*stack)->next->next->data))
		ra(stack);
	if (((*stack)->data > (*stack)->next->data) && 
		((*stack)->next->data < (*stack)->next->next->data))
		sa(stack);
 }

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	//t_stack	*current;

	find_min(&stack_a, &stack_b);
	ft_printf("Stack a:\n");
	print_list(stack_a);
	ft_printf("Stack b:\n");
	print_list(stack_b);
	//update_stack(&stack_a, min_value);
}


void    sort(t_stack *stack_a)
{
    int size;

    size = ft_lstsize((t_list *) stack_a);
    if (size == 2)
        sa(&stack_a);
    if (size == 3)
		sort_three(&stack_a);
    print_list(stack_a);
}