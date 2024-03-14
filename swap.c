/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:39:00 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/14 17:39:05 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void swap(t_stack **stack)
{
    int temp;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        ft_printf("Error\n");
        exit(-1);
    }
    temp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = temp;
}

void add_node(t_stack **stack_b, int data) 
{
    t_stack *new_node;
    
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL) {
        ft_printf("Memory allocation failed\n");
        exit(-1);
    }
    new_node->data = data;
    new_node->next = *stack_b;
    *stack_b = new_node;
}

void    push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    temp = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    temp->next = (*stack_b);
    (*stack_b) = (temp);
}
