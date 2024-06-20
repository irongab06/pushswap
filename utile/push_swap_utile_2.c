/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:24:56 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/20 13:07:08 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stock_value(int size, int divider, int i)
{
	if ((size % divider) == 1)
	{
		if (i == (size / divider))
			return (0);
	}
	else
	{
		if (i == (size / divider) - 1)
			return (0);
	}
	return (1);
}

int	stack_ascending(t_list	**stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->value < temp->next->value)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	find_median(t_list **stack_a, int size, int divider)
{
	int		stock_value;
	int		i;
	t_list	*temp;
	t_list	*browse;

	size = ft_lstsize(stack_a);
	temp = *stack_a;
	while (temp != NULL)
	{
		stock_value = temp->value;
		i = 0;
		browse = *stack_a;
		while (browse != NULL)
		{
			if (browse->value < stock_value)
				i++;
			browse = browse->next;
		}
		if (ft_stock_value(size, divider, i) == 0)
			return (stock_value);
		temp = temp->next;
	}
	return (0);
}

int	check_median(t_list **stack_a, int min_a, int median)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->value >= min_a && temp->value <= median)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	find_third_hight_value(t_list **stack_a, int third)
{
	int		first;
	int		second;
	t_list	*current;

	first = INT_MIN;
	second = INT_MIN;
	current = *stack_a;
	while (current != NULL)
	{
		if (current->value > first)
		{
			third = second;
			second = first;
			first = current->value;
		}
		else if (current->value > second && current->value < first)
		{
			third = second;
			second = current->value;
		}
		else if (current->value > third && current->value < second)
			third = current->value;
		current = current->next;
	}
	return (third);
}
