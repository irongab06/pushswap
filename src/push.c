/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:24:19 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:23:49 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;

	if (*stack_b == NULL)
		return ;
	temp_a = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	temp_a->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = temp_a;
	*stack_a = temp_a;
	(*stack_a)->prev = NULL;
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;

	if (*stack_a == NULL)
		return ;
	temp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = temp_a;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
	}
	else
	{
		temp_a->next = *stack_b;
		(*stack_b)->prev = temp_a;
		*stack_b = temp_a;
		(*stack_b)->prev = NULL;
	}
	write(1, "pb", 2);
	write(1, "\n", 1);
}
