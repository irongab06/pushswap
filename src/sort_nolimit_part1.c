/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nolimit_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:46:17 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/20 13:10:55 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_with_nolimit(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		median;
	int		divider;
	int		med_divider;

	size = 0;
	divider = ft_divider(stack_a);
	med_divider = ft_med_divider(divider);
	while (--divider != 1)
	{
		median = find_median(stack_a, size, divider);
		push_stack_b(stack_a, stack_b, med_divider, median);
	}
	median = find_median(stack_a, size, 1);
	push_stack_a(stack_a, stack_b, median, med_divider);
	if (ft_lstsize(stack_a) == 3)
		sort_for_3(stack_a);
	push_last_sort(stack_a, stack_b);
}

void	push_last_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_b;
	int	size;

	while ((*stack_b) != NULL)
	{
		size = ft_lstsize(stack_b);
		max_b = find_max(stack_b);
		last_sort_b_for_a(stack_a, stack_b, max_b, size);
	}
	while (stack_in_order(*stack_a) != 0)
		rra(stack_a, 0);
}

void	last_sort_b_for_a(t_list **stack_a, t_list **stack_b,
		int max_b, int size)
{
	t_list	*temp;
	int		start_lst;
	int		end_lst;

	start_lst = 0;
	end_lst = 0;
	temp = *stack_b;
	while (start_lst < size)
	{
		if (temp->value == max_b)
			break ;
		temp = temp->next;
		start_lst++;
	}
	temp = *stack_b;
	while (temp->next != NULL)
		temp = temp->next;
	while (end_lst < size - 1)
	{
		if (temp->value == max_b)
			break ;
		temp = temp->prev;
		end_lst++;
	}
	ft_print_command(stack_a, stack_b, start_lst, end_lst);
}

void	push_stack_a(t_list **stack_a, t_list **stack_b, int median,
		int med_divider)
{
	int	min_a;
	int	order_a;
	int	order_b;
	int	third_value;

	third_value = find_third_hight_value(stack_a, INT_MIN);
	while (ft_lstsize(stack_a) > 3)
	{
		min_a = find_min(stack_a);
		order_a = last_sort_a_for_b(stack_a, min_a, third_value);
		order_b = ft_position_b(stack_b, median, med_divider);
		if (stack_in_order(*stack_a) == 0 && stack_ascending(stack_b) == 0)
		{
			while ((*stack_b) != NULL)
				pa(stack_a, stack_b);
			return ;
		}
		first_dispatch_order_for_b(stack_a, stack_b, order_a, order_b);
	}
	order_b = ft_position_b(stack_b, median, med_divider);
	first_dispatch_order_for_b(stack_a, stack_b, 0, order_b);
	return ;
}

int	last_sort_a_for_b(t_list **stack_a, int min_a, int third_value)

{
	t_list	*temp;
	int		start_lst;
	int		size;

	start_lst = 0;
	temp = *stack_a;
	size = ft_lstsize(stack_a);
	while (start_lst < size)
	{
		if (temp->value >= min_a && temp->value < third_value)
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
