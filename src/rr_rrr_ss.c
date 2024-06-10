/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:17:22 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:23:58 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	write(1, "ss", 2);
	write(1, "\n", 1);
	sa(stack_a, 1);
	sb(stack_b, 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rr", 2);
	write(1, "\n", 1);
	ra(stack_a, 1);
	rb(stack_b, 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rrr", 3);
	write(1, "\n", 1);
	rra(stack_a, 1);
	rrb(stack_b, 1);
}
