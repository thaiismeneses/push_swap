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

#include "push_swap.h"

void    swap(t_stack **stack)
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

void    add_node(t_stack **stack, int data) 
{
    t_stack *new_node;
    
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL) {
        ft_printf("Memory allocation failed\n");
        exit(-1);
    }
    new_node->data = data;
    new_node->next = *stack;
    *stack = new_node;
}

void    push(t_stack **stack_src, t_stack **stack_dest)
{
    t_stack *temp;

    temp = (*stack_src);
    (*stack_src) = (*stack_src)->next;
    temp->next = (*stack_dest);
    (*stack_dest) = (temp);
}

void    rotate(t_stack **stack)
{
    t_stack *last;

    last = (*stack);
    while (last->next != NULL)
        last = last->next;
    last->next = (*stack);
    (*stack) = (*stack)->next;
    last->next->next = NULL;
}

void    reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *preview;

    last = (*stack);
    while (last->next != NULL)
    {
        preview = last;
        last = last->next;
    }
    last->next = (*stack);
    (*stack) = last;
    preview->next = NULL;
}
