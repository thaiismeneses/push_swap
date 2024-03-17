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
int	transform_input(char *str);
int	validating_int(long nbr);
int	has_duplicate(t_stack *stack, int nbr);
int is_in_order(t_stack *stack);
void	free_list(t_stack *stack);
void    swap(t_stack **stack);
void	print_list(t_stack *stack);
void    push(t_stack **stack_src, t_stack **stack_dest);
void    add_node(t_stack **stack, int data);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_b, t_stack **stack_a);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

#endif