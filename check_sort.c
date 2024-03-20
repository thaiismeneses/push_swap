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



void    sort(t_stack *stack)
{
    int size;

    size = ft_lstsize((t_list *) stack);
    if (size == 2)
        sa(&stack);
    if (size == 3)
    {
       /**TO DO*/
    }
    print_list(stack);
}