/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:13:13 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:23:53 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **stack_a, int rr)
{
	t_list	*first;
	t_list	*last;

	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (rr != 1)
	{
		write(1, "ra", 2);
		write(1, "\n", 1);
	}
}

void	rb(t_list **stack_b, int rr)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(stack_b) <= 1 || stack_b == NULL)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (rr != 1)
	{
		write(1, "rb", 2);
		write(1, "\n", 1);
	}
}

void	rra(t_list **stack_a, int rrr)
{
	t_list	*before_last;
	t_list	*last;

	before_last = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	while (before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	last->next = *stack_a;
	(*stack_a)->prev = last;
	before_last->next = NULL;
	last->prev = NULL;
	*stack_a = last;
	if (rrr != 1)
	{
		write(1, "rra", 3);
		write(1, "\n", 1);
	}
}

void	rrb(t_list **stack_b, int rrr)
{
	t_list	*before_last;
	t_list	*last;

	before_last = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	while (before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	last->next = *stack_b;
	(*stack_b)->prev = last;
	before_last->next = NULL;
	last->prev = NULL;
	*stack_b = last;
	if (rrr != 1)
	{
		write(1, "rrb", 3);
		write(1, "\n", 1);
	}
}
