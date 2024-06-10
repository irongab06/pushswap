/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:59:23 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:24:41 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_dispatcher(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) <= 2)
		sort_for_2(stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_for_3(stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_for_5(stack_a, stack_b);
	else if (ft_lstsize(stack_a) > 5)
		sort_with_nolimit(stack_a, stack_b);
}

int	find_min(t_list **stack_a)
{
	t_list	*temp;
	int		value_min;

	temp = NULL;
	if (*stack_a == NULL)
		return (0);
	temp = *stack_a;
	value_min = temp->value;
	while (temp->next != NULL)
	{
		if (temp->next->value < value_min)
		{
			value_min = temp->next->value;
		}
		temp = temp->next;
	}
	return (value_min);
}

int	find_max(t_list **stack_a)
{
	t_list	*temp;
	int		value_max;

	temp = *stack_a;
	if (temp == NULL)
		return (0);
	value_max = temp->value;
	while (temp->next != NULL)
	{
		if (temp->next->value > value_max)
		{
			value_max = temp->next->value;
		}
		temp = temp->next;
	}
	return (value_max);
}
