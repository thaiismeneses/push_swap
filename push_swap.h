/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:11 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/20 13:14:06 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libraries/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648


typedef enum e_bool
{
	false,
	true,
}t_bool;

# define FALSE 0
# define TRUE 1

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	t_bool			above_median;
	t_bool			lowest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		param_check(int flag, char *str);
int		has_duplicate(t_stack *stack, int nbr);
int		is_in_order(t_stack *stack);
void	errors_exit(int flag, char *str);
void	free_list(t_stack *stack);
void	swap(t_stack **stack);
void	print_list(t_stack *stack);
void	push(t_stack **stack_src, t_stack **stack_dest);
t_stack	*last_from_list(t_stack *stack);
void	add_node(t_stack **stack, int nbr);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void    sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_more_than_three(t_stack **stack_a, t_stack **stack_b);

#endif
