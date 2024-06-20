/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:12 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/20 13:33:34 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp_1;

	temp_1 = *stack_a;
	while (temp_1)
	{
		temp = temp_1->next;
		free(temp_1);
		temp_1 = temp;
	}
}
