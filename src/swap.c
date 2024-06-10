/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:17:42 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:24:28 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a, int ss)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(stack_a) <= 1 || stack_a == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack_a = second;
	if (ss != 1)
	{
		write(1, "sa", 2);
		write(1, "\n", 1);
	}
}

void	sb(t_list **stack_b, int ss)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(stack_b) <= 1 || stack_b == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack_b = second;
	if (ss != 1)
	{
		write(1, "sb", 2);
		write(1, "\n", 1);
	}
}
