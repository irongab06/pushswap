/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:43:11 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:24:07 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_for_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	while (stack_in_order(*stack_a) != 0)
	{	
		first = (*stack_a)->value;
		second = (*stack_a)->next->value;
		third = (*stack_a)->next->next->value;
		if (first > second && second < third && first < third)
			sa(stack_a, 0);
		else if(first < second && second > third)
			rra(stack_a, 0);
		else if(first < second && second > third)
			rra(stack_a, 0);
		else if(first > second && second > third)
			ra(stack_a, 0);
		else if (first > second && second < third)
			ra(stack_a, 0);
	}	
}