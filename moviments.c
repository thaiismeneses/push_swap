/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:39:00 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 12:00:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if (!stack_src || !(*stack_src))
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	temp->prev = NULL;
	if (!*stack_dest)
	{
		*stack_dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_dest;
		temp->next->prev = temp;
		*stack_dest = temp;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_from_list(*stack);
	last->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_from_list(*stack);
	last->prev->next = NULL;
	last->next = (*stack);
	last->prev = NULL;
	(*stack) = last;
	last->next->prev = last;
}
