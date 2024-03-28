/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:49:11 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/27 12:12:49 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libraries/ft_printf/ft_printf.h"
# include "libraries/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_bool
{
	false,
	true,
}					t_bool;

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	t_bool			above_median;
	t_bool			lowest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				param_check(int flag, char **argv, t_stack **stack);
int					has_duplicate(t_stack *stack, int nbr);
t_bool				is_in_order(t_stack *stack);
void				errors_exit(int flag, char **str, t_stack **stack);
void				handle_arguments(int argc, char **argv, t_stack **stack_a);
void				final_free(int flag, t_stack **a, char **av);

// dealing with lists
int					lst_size(t_stack *stack);
void				free_list(t_stack **stack);
void				print_list(t_stack *stack);
void				add_node(t_stack **stack, int nbr);

// movements and operations
void				swap(t_stack **stack);
void				push(t_stack **stack_src, t_stack **stack_dest);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				sa(t_stack **stack_a, t_bool print);
void				sb(t_stack **stack_b, t_bool print);
void				ss(t_stack **stack_a, t_stack **stack_b, t_bool print);
void				pa(t_stack **stack_b, t_stack **stack_a, t_bool print);
void				pb(t_stack **stack_a, t_stack **stack_b, t_bool print);
void				ra(t_stack **stack_a, t_bool print);
void				rb(t_stack **stack_b, t_bool print);
void				rr(t_stack **stack_a, t_stack **stack_b, t_bool print);
void				rra(t_stack **stack_a, t_bool print);
void				rrb(t_stack **stack_b, t_bool print);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_bool print);
void				rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest_node);
void				rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest_node);

// walking through the list
t_stack				*last_from_list(t_stack *stack);
t_stack				*find_node_min(t_stack *stack);
t_stack				*find_node_max(t_stack *stack);

// working with sorts
// void	sort(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack);
void				sort_more_than_three(t_stack **stack_a, t_stack **stack_b);

// treating nodes from SA and SB
void				current_index(t_stack *stack);
void				set_target_a(t_stack *stack_a, t_stack *stack_b);
void				cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
void				set_cheapest(t_stack *stack);
void				start_nodes_a(t_stack *stack_a, t_stack *stack_b);
void				set_target_b(t_stack *stack_a, t_stack *stack_b);
void				start_nodes_b(t_stack *stack_a, t_stack *stack_b);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_id);
t_stack				*get_cheapest(t_stack *stack);
void				move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void				move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void				min_on_top(t_stack **stack_a);
#endif
