/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:13:09 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/20 13:33:12 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		check_argv(argc, argv);
		init_stack(&stack_a, argv + 1);
		check_duplicate(&stack_a);
		if (stack_in_order(stack_a) == 1)
			algo_dispatcher(&stack_a, &stack_b);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
	}
	return (0);
}
