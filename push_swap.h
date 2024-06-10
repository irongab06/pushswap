/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:04:33 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 12:14:39 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	long long		value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

//--------------------------------------------------------------

int		check_digit(char *str);

//--------------------------------------------------------------

void	check_argv(int argc, char **argv);
void	check_duplicate(t_list **stack_a);
void	init_stack(t_list **t_list, char **argv);
void	sa(t_list **stack_a, int ss);
void	sb(t_list **stack_b, int ss);
void	ss(t_list **stack_a, t_list **stack_b);
void	ft_free(char **str);
void	algo_dispatcher(t_list **stack_a, t_list **stack_b);
void	sort_for_2(t_list **stack_a);
void	sort_for_3(t_list **stack_a);
void	sort_for_5(t_list **stack_a, t_list **stack_b);
void	sort_with_nolimit(t_list **stack_a, t_list **stack_b);
void	push_stack_b(t_list **stack_a, t_list **stack_b, int size, int median);
void	push_stack_a(t_list **stack_a, t_list **stack_b, int median,
			int third_value);
void	last_sort_b_for_a(t_list **stack_a, t_list **stack_b, int max_b);
void	push_last_sort(t_list **stack_a, t_list **stack_b);
void	dispatch_order_for_b(t_list **stack_a, t_list **stack_b, int order_a,
			int order_b);
void	first_dispatch_order_for_b(t_list **stack_a, t_list **stack_b,
			int order_a, int order_b);
void	ra(t_list **stack_a, int rr);
void	rb(t_list **stack_b, int rr);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int rrr);
void	rrb(t_list **stack_b, int rrr);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//--------------------------------------------------------------

int		ft_error(char **str);
int		find_min(t_list **stack_a);
int		find_max(t_list **stack_a);
int		find_median(t_list **stack_a, int size, int divider);
int		find_median_5(t_list **stack_a, int size);
int		find_median_4(t_list **stack_a, int size);
int		find_median_3(t_list **stack_a, int size);
int		find_median_2(t_list **stack_a, int size);
int		ft_error_lst(t_list **stack_a);
int		stack_in_order(t_list *stack_a);
int		stack_ascending(t_list **stack_a);
int		ft_lstsize(t_list **stack_a);
int		last_sort_a_for_b(t_list **stack_a, int min_a, int third_value);
int		ft_position(t_list **stack_a, int min_a, int median);
int		check_median(t_list **stack_a, int min_a, int median);
int		ft_position_b(t_list **stack_b, int max_b, int median);
int		ft_last_value(t_list **stack_a);
int		find_third_hight_value(t_list **stack_a);

//--------------------------------------------------------------

t_list	*ft_lstnew_int(long long value);
t_list	*ft_lstlast(t_list *lst);

//--------------------------------------------------------------

void	ft_lstadd_back(t_list **lst, t_list *new);
#endif
