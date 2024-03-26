/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:09 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/20 11:37:20 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, t_bool print)
{
	swap(stack_a);
	if (!print)
		ft_printf("sa\n");
}

void	pa(t_stack **stack_b, t_stack **stack_a, t_bool print)
{
	push(stack_b, stack_a);
	if (!print)
		ft_printf("pa\n");
}

void	ra(t_stack **stack_a, t_bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void	rra(t_stack **stack_a, t_bool print)
{
	reverse_rotate(stack_a);
	if (!print)
		ft_printf("rra\n");
}
