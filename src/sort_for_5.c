/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irongab <irongab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:43:52 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 21:56:13 by irongab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_for_5(t_list **stack_a, t_list **stack_b)
{
	int	value_min;
	int	value_max;

	value_min = find_min(stack_a);
	value_max = find_max(stack_a);
	while (ft_lstsize(stack_a) != 3)
	{
		if (value_min == (*stack_a)->value || value_max == (*stack_a)->value)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 0);
	}
	sort_for_3(stack_a);
	while (ft_lstsize(stack_b) > 0)
	{
		if (value_min == (*stack_b)->value)
			pa(stack_a, stack_b);
		else if (value_max == (*stack_b)->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a, 0);
		}
	}
}
