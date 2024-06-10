#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	//int	i;

	//i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{	
		check_argv(argc, argv);
		init_stack(&stack_a, argv + 1);
		check_duplicate(&stack_a);
		if (stack_in_order(stack_a) == 1)
		{
			algo_dispatcher(&stack_a, &stack_b);
		}
		/*	
		while (stack_a)
		{
			printf("stock_a : %lli\n", stack_a->value);
			//i++;
			//printf("i = %i\n", i);
			stack_a = stack_a->next;
		}
		*/
	/*
		printf("\n");
		
		
		while (stack_b)
		{
			printf("stock_b : %lli\n", stack_b->value);
			stack_b = stack_b->next;

		}
		*/
	}	
	return (0);
}

