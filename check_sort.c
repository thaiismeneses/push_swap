/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:44 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/15 13:49:47 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_in_order(t_stack *stack)
{
	t_stack *current;

    current = stack;
    while (current != NULL && current->next != NULL)
	{
       // ft_printf("Current element: %d, Next element: %d\n", current->data, current->next->data);
        if (current->data > current->next->data) 
		{
         //   ft_printf("Found element out of order: %d > %d\n", current->data, current->next->data);
            return (0);
        }
        current = current->next;
    }
    //ft_printf("All elements are in order\n");
    return (1);
}