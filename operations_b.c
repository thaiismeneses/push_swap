/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:43 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/20 11:38:36 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b, t_bool print)
{
	swap(stack_b);
	if (!print)
		ft_printf("sb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	push(stack_a, stack_b);
	if (!print)
		ft_printf("pb\n");
}

void	rb(t_stack **stack_b, t_bool print)
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

void	rrb(t_stack **stack_b, t_bool print)
{
	reverse_rotate(stack_b);
	if (!print)
		ft_printf("rrb\n");
}
