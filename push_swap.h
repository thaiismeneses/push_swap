/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:11 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/13 14:06:12 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libraries/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
    int data;
    struct s_stack *next;
}   t_stack;

int	param_check(char *str);
int	validating(long nbr);
int	has_duplicate(t_stack *stack_a, int nbr);
void	free_list(t_stack *stack_a);
void swap(t_stack **stack);
void	print_list(t_stack *stack_a);
void    push(t_stack **stack_a, t_stack **stack_b);
void add_node(t_stack **stack_b, int data);


#endif