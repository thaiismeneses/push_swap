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
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
 {
	if (((*stack)->nbr < (*stack)->next->nbr) &&
		((*stack)->next->nbr > (*stack)->next->next->nbr))
		rra(stack);
	else if (((*stack)->nbr > (*stack)->next->nbr) &&
		((*stack)->nbr > (*stack)->next->next->nbr))
		ra(stack);
	if (((*stack)->nbr > (*stack)->next->nbr) && 
		((*stack)->next->nbr < (*stack)->next->next->nbr))
		sa(stack);
 }

void	sort_more_than_three(t_stack **stack_a, t_stack **stack_b)
{
	
}


void    sort(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    size = ft_lstsize((t_list *) stack_a);
	ft_printf("size:%d \n", size);
    if (size == 2)
        sa(stack_a);
    if (size == 3)
		sort_three(stack_a);
	else
		sort_more_than_three(stack_a, stack_b);
   //print_list(stack_a);
}