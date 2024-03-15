/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:09 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/15 14:01:12 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

void    pa(t_stack **stack_b, t_stack **stack_a)
{
    push(stack_b, stack_a);
    ft_printf("pa\n");
}

void    ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}

void    rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}