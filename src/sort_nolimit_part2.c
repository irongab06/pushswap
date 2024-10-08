/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nolimit_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:47:19 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/20 13:07:54 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack_b(t_list **stack_a, t_list **stack_b, int med_divider,
		int median)
{
	int	min_a;
	int	order_a;
	int	order_b;

	min_a = find_min(stack_a);
	while (check_median(stack_a, min_a, median) != 0)
	{
		if (ft_lstsize(stack_a) == 4)
			return ;
		order_a = ft_position(stack_a, min_a, median);
		order_b = ft_position_b(stack_b, median, med_divider);
		first_dispatch_order_for_b(stack_a, stack_b, order_a, order_b);
		if (check_median(stack_a, min_a, median) == 0)
			order_b = ft_position_b(stack_b, median, med_divider);
	}
}

int	ft_position(t_list **stack_a, int min_a, int median)
{
	t_list	*temp;
	int		start_lst;
	int		size;

	start_lst = 0;
	temp = *stack_a;
	size = ft_lstsize(stack_a);
	while (start_lst < size)
	{
		if (temp->value >= min_a && temp->value <= median)
			break ;
		temp = temp->next;
		start_lst++;
	}
	if (start_lst == 0)
		return (4);
	else
		return (2);
	return (0);
}

int	ft_position_b(t_list **stack_b, int median, int med_divider)
{
	t_list		*temp;
	static int	i;

	temp = *stack_b;
	if (temp == NULL)
		return (0);
	if (temp->value == median)
	{
		i = temp->value;
		return (0);
	}
	if (temp->value <= (median - med_divider) && temp->value != i)
		return (2);
	if (temp->value > (median - med_divider))
	{
		i = temp->value;
		if (temp->next != NULL && (*stack_b)->value < (*stack_b)->next->value)
			return (1);
		return (0);
	}
	i = temp->value;
	return (0);
}

void	first_dispatch_order_for_b(t_list **stack_a, t_list **stack_b,
		int order_a, int order_b)
{
	if (order_a == 1 && order_b == 1)
	{
		ss(stack_a, stack_b);
		return ;
	}
	if (order_a == 2 && order_b == 2)
	{
		rr(stack_a, stack_b);
		return ;
	}
	if (order_a == 2)
		ra(stack_a, 0);
	if (order_b == 2)
		rb(stack_b, 0);
	if (order_b == 1)
		sb(stack_b, 0);
	if (order_a == 1)
		sa(stack_a, 0);
	if (order_a == 4)
		pb(stack_a, stack_b);
}

void	ft_print_command(t_list **stack_a, t_list **stack_b,
		int start_lst, int end_lst)
{
	if (start_lst == 0)
		pa(stack_a, stack_b);
	else if (start_lst <= end_lst || start_lst - 1 == end_lst)
		rb(stack_b, 0);
	else if (start_lst > end_lst)
		rrb(stack_b, 0);
}
