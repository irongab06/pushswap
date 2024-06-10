#include "push_swap.h"

void	sort_for_2(t_list **stack_a)
{
	while (stack_in_order(*stack_a) != 0)
		sa(stack_a, 0);
}

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
	while  (ft_lstsize(stack_b) > 0)		
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
void	sort_with_nolimit(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	median;
	int	divider;
	int	third_value;
	t_list	*temp_b;
	//t_list	*temp_a;

	size = ft_lstsize(stack_a);
	while (stack_in_order(*stack_a) != 0) //controle si a n est pas en ordre decroissant
	{		
			if(size <= 50)
			{			
				push_stack_b(stack_a, stack_b, size, 2);
				push_stack_a(stack_a, stack_b, size, median, third_value);	
				push_last_sort(stack_a, stack_b);
			


			}
			else if (size > 50)
			{
				
				divider = 5;
				while (divider != 1)
				{
					size = ft_lstsize(stack_a);
					//printf("size : %i\n", size);	
					median = find_median(stack_a, size, divider);
					//printf("median1 : %i\n", median);	
					push_stack_b(stack_a, stack_b, size, median);
				
				//	temp_b = *stack_b;
				//	while (temp_b)
				//	{
				//		printf("temp_b : %lli\n", temp_b->value);
				//		temp_b = temp_b->next;
				//	}
				//	
					size = ft_lstsize(stack_a);	
					divider--;
				}
					
				size = ft_lstsize(stack_a);
				//printf("SIZEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE : %i\n", size);	
				median = find_median(stack_a, size, 1);
				//push_stack_b(stack_a, stack_b, size, median);
				third_value = find_third_hight_value(stack_a);
				//printf("median %i\n", median);
				//printf("third_value %i\n", third_value);	
				push_stack_a(stack_a, stack_b, size, median, third_value);
			//	push_stack_b(stack_a, stack_b, size, 97);

				if (ft_lstsize(stack_a) == 3)
				{
					//printf("3333333333333333333333333333333");
					sort_for_3(stack_a);
				}
			/*	
				temp_b = *stack_b;
				while (temp_b)
				{
					printf("temp_b : %lli\n", temp_b->value);
					temp_b = temp_b->next;
				}
				*/
/*
				printf("\n\n");
				temp_a = *stack_a;
				
				while (temp_a)
				{
					printf("temp_a : %lli\n", temp_a->value);
					temp_a = temp_a->next;
				}
*/
				//printf("ONVA REUSSIRRRRRRRRRRRRRRR");
				//push_stack_a(stack_a, stack_b, size, median, third_value);
							
				
				temp_b = *stack_b;
				while (temp_b)
				{
					printf("temp_b : %lli\n", temp_b->value);
					temp_b = temp_b->next;
				}
				push_last_sort(stack_a, stack_b);
				
			}
	}	

}
void	push_last_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_b;
	//int	max_a;
	//t_list	*temp_a;
	//t_list	*temp_b;
	
//	temp_b = *stack_b;
//	temp_a = *stack_a;
	while ((*stack_b) != NULL)
	{	
		max_b = find_max(stack_b);
		//max_a = find_max(stack_a);
		/*
		temp_b = *stack_b;
		temp_a = *stack_a;
		
		while (temp_a)
		{
			printf("temp_a : %lli\n", temp_a->value);
			temp_a = temp_a->next;
		}
		printf("\n");
		while (temp_b)
		{
			printf("temp_b : %lli\n", temp_b->value);
			temp_b = temp_b->next;
		}
*/
		//last_sort_b_for_a(stack_a, stack_b, max_b, max_a);
		last_sort_b_for_a(stack_a, stack_b, max_b);
		/*
		temp_a = *stack_a;
		while (temp_a)
		{
			printf("temp_a : %lli\n", temp_a->value);
			temp_a = temp_a->next;
		}
	*/

	}
	/*
	temp_a = *stack_a;
	while (temp_a)
	{
		printf("temp_a : %lli\n", temp_a->value);
		temp_a = temp_a->next;
	}
	*/
	while (stack_in_order(*stack_a) != 0)
	{
		//printf("ERERERERERER");	
		rra(stack_a, 0);
	}	
	/*
	temp_a = *stack_a;
	while (temp_a)
	{
		printf("temp_a : %lli\n", temp_a->value);
		temp_a = temp_a->next;
	}
*/
		
	
}
/*
void	last_sort_b_for_a(t_list **stack_a, t_list **stack_b, int max_b, int max_a) // esssai
{
	t_list	*temp_b; 
	int	start_lst;
	int	end_lst;
	int	size;
	int	end_a;
	//static int	i;

	start_lst = 0;
	end_lst = 0;
	temp_b = *stack_b;
	size = ft_lstsize(stack_b);
	while (start_lst < size)
	{
		if (temp_b->value == max_b)
			break ;
		temp_b = temp_b->next;
		start_lst++;
	}
 	temp_b = *stack_b;
 	while (temp_b->next !=  NULL)
		temp_b = temp_b->next;
	while (end_lst < size - 1)
	{
		if (temp_b->value == max_b)
			break ;
		temp_b = temp_b->prev;
		end_lst++;
	}
	
	//i++;
	//printf("i = %i\n", i);
	end_a = ft_last_value(stack_a);
	if (ft_lstsize(stack_b) <= 3)
	{	
		if ((*stack_b)->value < (*stack_a)->value && ((*stack_b)->value > end_a || end_a == max_a))
			pa(stack_a, stack_b);
		else if ((*stack_b)->value < (*stack_a)->value && (*stack_b)->value < end_a && end_a != max_a)
		{
			//printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ");
			rra(stack_a, 0);
		}	
		else if ((*stack_b)->value > (*stack_a)->value)
			ra(stack_a, 0);
		return ;

	}	
	if (start_lst <= end_lst || start_lst - 1 == end_lst)
	{	
		if ((*stack_b)->value < (*stack_a)->value && ((*stack_b)->value > end_a || end_a == max_a))
			pa(stack_a, stack_b);
		else if ((*stack_b)->value < (*stack_a)->value && (*stack_b)->value < end_a && end_a != max_a)	
			rra(stack_a, 0);
		else if ((*stack_b)->value > (*stack_a)->value)
			ra(stack_a, 0);
		return ;
	}
	if (start_lst > end_lst)
	{	
		rrb(stack_b, 0);	
		if ((*stack_b)->value < (*stack_a)->value && ((*stack_b)->value > end_a || end_a == max_a))
			pa(stack_a, stack_b);
		else if ((*stack_b)->value < (*stack_a)->value && (*stack_b)->value < end_a && end_a != max_a)
			rra(stack_a, 0);
		else if ((*stack_b)->value > (*stack_a)->value)
			ra(stack_a, 0);
		return ;
	}

// essai
}

*/

void	last_sort_b_for_a(t_list **stack_a, t_list **stack_b, int max_b)
{
	t_list	*temp;
	int	start_lst;
	int	end_lst;
	int	size;
	//static int	i;

	start_lst = 0;
	end_lst = 0;
	temp = *stack_b;
	size = ft_lstsize(stack_b);
	while (start_lst < size)
	{
		if (temp->value == max_b)
			break ;
		temp = temp->next;
		start_lst++;
	}
 	temp = *stack_b;
 	while (temp->next !=  NULL)
		temp = temp->next;
	while (end_lst < size - 1)
	{
		if (temp->value == max_b)
			break ;
		temp = temp->prev;
		end_lst++;
	}
	
	//i++;
	//printf("i = %i\n", i);

	if (start_lst == 0)
		pa(stack_a, stack_b);
	else if (start_lst <= end_lst || start_lst - 1 == end_lst)
		rb(stack_b, 0);
	else if (start_lst > end_lst)
		rrb(stack_b, 0);

	//------------------------------------------------------------
	

	

	
}


void	push_stack_a(t_list **stack_a, t_list **stack_b, int size, int median, int third_value)
{
	int	min_a;
	int	max_b;
	int	order_a;
	int	order_b;
	(void)size;
	//static int	i;
	//printf("LAAAAAAAAAAAAAAAAA\n");
	while (stack_in_order(*stack_a) != 0) //&& //ft_lstsize(stack_a) != size)
	{
		while (ft_lstsize(stack_a) > 3)
		{       
			max_b = find_max(stack_b);
			min_a = find_min(stack_a);
			order_a = last_sort_a_for_b(stack_a, min_a, third_value);
			//order_a = ft_position(stack_a, min_a, median);
			//printf("order_a %i\n", order_a);
			order_b = ft_position_b(stack_b, max_b, median);					
			//printf("order_b %i\n", order_b);
			if (stack_in_order(*stack_a) == 0 && stack_ascending(stack_b) == 0)
			{
				while ((*stack_b) != NULL)
					pa(stack_a, stack_b);
				return ;
			}
			//i++;
			//printf("A = %i\n", i);	
			first_dispatch_order_for_b(stack_a, stack_b, order_a, order_b);
		}
			order_b = ft_position_b(stack_b, max_b, median);					
			first_dispatch_order_for_b(stack_a, stack_b, 0, order_b);
		//sort_for_3(stack_a);
		return ;
	}	
}

int	last_sort_a_for_b(t_list **stack_a, int min_a, int third_value)
{
	t_list	*temp;
	int	start_lst;
	int	end_lst;
	int	size;

	start_lst = 0;
	end_lst = 0;
	temp = *stack_a;
	size = ft_lstsize(stack_a);
	//printf("THIRDDDDDDVALUE : %i\n", third_value);
	while (start_lst < size)
	{
		if (temp->value >= min_a && temp->value < third_value)
			break ;
		temp = temp->next;
		start_lst++;
	}
 	temp = *stack_a;
 	while (temp->next !=  NULL)
		temp = temp->next;
	while (end_lst < size - 1)
	{
		if (temp->value >= min_a && temp->value < third_value)
			break ;
		temp = temp->prev;
		end_lst++;
	}
	if (start_lst == 0)
		return (4);
	else
		return (2);
	/*
	if (start_lst <= end_lst || start_lst - 1 == end_lst)
		return (2);
	else if (start_lst > end_lst)
	{
		//printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
		//printf("value_a %lli\n", (*stack_a)->value);	
		return (3);
	}
	*/
	return (0);
	


}

void	push_stack_b(t_list **stack_a, t_list **stack_b, int size, int median)
{
	int	max_b;
	int	min_a;
	int	order_a;
	int	order_b;
	//static int	i;

	//t_list	*temp_a;
	//t_list	*temp_b;
	(void)size;
	//temp_a = *stack_a;
	//temp_b = *stack_b;
	min_a = find_min(stack_a);
	while (check_median(stack_a, min_a, median) != 0)
	{
		if (ft_lstsize(stack_a) == 3)
			return ;	
		max_b = find_max(stack_b);
		order_a = ft_position(stack_a, min_a, median);
		//printf("order_a : %i\n", order_a);
		
		//printf("median : %i\n", median);
		order_b = ft_position_b(stack_b, max_b, median);
		//printf("order_b : %i\n", order_b);
		//i++;
		//printf("i = %i\n", i);
		first_dispatch_order_for_b(stack_a, stack_b, order_a, order_b);
		if (check_median(stack_a, min_a, median) == 0)
			order_b = ft_position_b(stack_b, max_b, median);		
	/*	
		temp_a = *stack_a;
		temp_b = *stack_b;
		
		while (temp_a)
		{
			printf("temp_a : %lli\n", temp_a->value);
			temp_a = temp_a->next;
		}
		printf("\n");
		
		temp_b = *stack_b;
		while (temp_b)
		{	
			printf("temp_b : %lli\n", temp_b->value);
			temp_b = temp_b->next;
		}
	*/	
	/*	
	}	
	median = find_median(stack_a, ft_lstsize(stack_a));
	//printf("median : %i\n", median);
	min_a = find_min(stack_a);
	while (check_median(stack_a, min_a, median) != 0)
	{
		
		max_b = find_max(stack_b);
		order_a = ft_position(stack_a, min_a, median);
		//printf("order_a : %i\n", order_a);
		order_b = ft_position_b(stack_b, max_b);
		//printf("order_b : %i\n", order_b);
		dispatch_order_for_b(stack_a, stack_b, order_a, order_b);
		temp_a = *stack_a;
		temp_b = *stack_b;
		
		while (temp_a)
		{
			printf("temp_a : %lli\n", temp_a->value);
			temp_a = temp_a->next;
		}
		printf("\n");
		while (temp_b)
		{	
			printf("temp_b : %lli\n", temp_b->value);
			temp_b = temp_b->next;
		}
		*/
	}
}

int	check_median(t_list **stack_a, int min_a, int median)
{
	t_list	*temp;
	
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->value >= min_a && temp->value <= median)
		{
			return (1);
		}	
		temp = temp->next;
	}
	return (0);
}	
	
int	ft_position(t_list **stack_a, int min_a, int median)
{
	t_list	*temp;
	int	start_lst;
	int	end_lst;
	int	size;
	//int	max_value;
	
	//max_value = find_max(stack_a);
	//printf("max_value = %i\n", max_value);
	start_lst = 0;
	end_lst = 0;
	temp = *stack_a;
	size = ft_lstsize(stack_a);
	while (start_lst < size)
	{
		if (temp->value >= min_a && temp->value <= median)
			break ;
		temp = temp->next;
		start_lst++;
	}
 	temp = *stack_a;
 	while (temp->next !=  NULL)
		temp = temp->next;	
	while (end_lst < size - 1)
	{
		if (temp->value >= min_a && temp->value <= median)
			break ;
		temp = temp->prev;
		end_lst++;
	}
	//if ((*stack_a)->value <= max_value && (*stack_a)->value >= max_value - 2)
	//	return (2)u;
	/*	
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		//printf("stack_a->value : %lli\n", (*stack_a)->value);
		//printf("essai\n");	
		return (1);
	}
	*/	
	if (start_lst == 0)
		return (4);
	else
		return (2);
	//if (start_lst <= end_lst || start_lst - 1 == end_lst)
	//	return (2);
	//else if (start_lst > end_lst)
	//	return (3);
	return (0);
	

}



int	ft_position_b(t_list **stack_b, int size, int median)
{

	(void)size;
	t_list	*temp;
	static int	i;
	
	//printf("i : %i\n", i);
	temp = *stack_b;
	if (temp == NULL)
		return (0);
	if (temp->value == median)
	{
		i = temp->value;	
		return (0);
	}
	if (temp->value <= (median - 11) && temp->value != i)
	{
	/*	
		if (ft_lstsize(stack_b) == 1)
			return (0);
		if ((*stack_b)->value < ft_last_value(stack_b))
			return (3);
		if ((*stack_b)->next != NULL && (*stack_b)->value > (*stack_b)->next->value && (*stack_b)->next->value <= (median - 11))
			return (1);	
		*/	
		//printf("TEMPS_VALUE = %lli\n", temp->value);
		//i = temp->value;
		
		return (2);
	}
	if (temp->value > (median - 11))
	{
		i = temp->value;
		if (temp->next != NULL && (*stack_b)->value < (*stack_b)->next->value)
			return (1);	
		return (0);
	}
	i = temp->value;
	return (0);
}

/*
int	ft_position_b(t_list **stack_b, int max_b)
{

	t_list	*temp;
	int	start_lst;
	int	end_lst;
	int	size;
	
	start_lst = 0;
	end_lst = 0;
	temp = *stack_b;
	size = ft_lstsize(stack_b);
	if (size == 0)
		return (0);
	while (start_lst < size)
	{
		if (temp->value == max_b)
			break ;
		temp = temp->next;
		start_lst++;
	}
 	temp = *stack_b;
 	while (temp->next !=  NULL)
	{	
		temp = temp->next;
	}	
	while (end_lst < size - 1)
	{

		if (temp->value == max_b)
			break ;
		temp = temp->prev;
		end_lst++;
	}
	temp = *stack_b;
	//----------------------------	
	if (temp->value < max_b / 2)
	{
		printf("temp->value = %lli\n", temp->value);
		return (2);
	}
	//--------------------------
	if (size == 1)
		return (0);
	if (temp->value == max_b)
		return (0);
	//printf("start_lst : %i\n", start_lst);
	if (start_lst == 1 && size > 2)
	{
		//printf("test");		
		if (temp->value > temp->next->next->value)
			return (1);
		if (temp->value < temp->next->next->value)
			return (2);
	}
	//printf("temp->value : %lli\n", temp->value);
	if (size == 2 && temp->value < temp->next->value)
	{ 
		return (12); //sa ou ra
	}

	if (start_lst - 1 < end_lst)
		return (2);
	if (start_lst - 1 > end_lst)
		return (3);
	return (0);
}
*/
/*
-------------------------------------------------------------		
	t_list	*temp;
	int	size;
	
	temp = *stack_b;
	size = ft_lstsize(stack_b);
	if (size == 0)
		return (0);
	if (temp->value == max_b)
		return (0);
	if (size == 2 && temp->value < temp->next->value)
		return (1);
	if (temp->value < temp->next->value && temp->value > temp->next->next->value)
		return (1);
	return (2);
	
		
*/

int	stack_ascending(t_list	**stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->value < temp->next->value)
		{
			//printf("ascending\n");
			return (1);
		}	
		temp = temp->next;
	}
	return (0);
}

int	find_median(t_list **stack_a, int size, int divider)
{
	int	stock_value;
	int	i;
	t_list	*temp;
	t_list	*browse;

	temp = *stack_a;
	while (temp != NULL)
	{
		stock_value = temp->value;
		i = 0;
		browse = *stack_a;
		while (browse != NULL)
		{
			if (browse->value < stock_value)
			{	
				i++;
			}
			browse = browse->next;
		}	
		if ((size % divider) == 1)
		{
 			if (i == (size / divider))
				return (stock_value);
		}
		else
 		{
 			if (i == (size / divider) - 1)
 				return (stock_value);
     		}		
		temp = temp->next;
	}
	return (0);
}

void	first_dispatch_order_for_b(t_list **stack_a, t_list **stack_b, int order_a, int order_b)
{
	if (order_a == 1 && order_b == 1)
	{
		ss(stack_a, stack_b);
		return ;
	}	
	if (order_a == 2 && order_b == 2)
	{	
		rr(stack_a, stack_b);
		return ; 
	}
	if (order_a == 3 && order_b == 3)
	{	
	rrr(stack_a, stack_b);
		return ;
	}	

	if (order_a == 2)
		ra(stack_a, 0);
	if (order_b == 2)
		rb(stack_b, 0);
	if (order_b == 3)
		rrb(stack_b, 0);
	if (order_a == 3)
		rra(stack_a, 0);
	if (order_b == 1)
		sb(stack_b, 0);
	if (order_a == 1)
		sa(stack_a, 0);
	if (order_a == 4 )
		pb(stack_a, stack_b);



}	

void	dispatch_order_for_b(t_list **stack_a, t_list **stack_b, int order_a, int order_b)
{	
	if (order_a == 4 && order_b == 0)
	{	
		pb(stack_a, stack_b);
		return ;
	}
	if (order_a == 1 && order_b == 1)
	{
		ss(stack_a, stack_b);
		return ;
	}	
	if (order_a == 2 && order_b == 2)
	{	
		rr(stack_a, stack_b);
		return ; 
	}	
	//if (order_a == 3 && order_b == 3)
	//	rrr(stack_a, stack_b, 1);
	if ((order_a == 2 && order_b == 12) || (order_a == 12 && order_b == 2))
	{
		rr(stack_a, stack_b);
		return ;
	}	
	if ((order_a == 1 && order_b == 12) || (order_a == 12 && order_b == 1))
	{
		ss(stack_a, stack_b);
		return ;
	}
	if (order_a == 12 || order_a == 1)
	{
		//printf("test sa\n");	
		sa(stack_a, 0);
	}	
	if (order_b == 12 || order_b == 1)
	{	
		//printf("test sbi\n");	
		sb(stack_b, 0);
	}	
	if (order_a == 2)
		ra(stack_a, 0);
	if (order_b == 2)
		rb(stack_b, 0);
	if (order_a == 3)
		rra(stack_a, 0);
	//if (order_a == 4)
	//	pb(stack_a, stack_b);
	//if (order_b == 3);
	//	rrb(stack_b, 0);

		
	/*
	if (order_a == 1 && order_b  == 1)
		ss(stack_a, stack_b);
	else if (order_a == 1)
		sa(stack_a, 0);
	else if (order_b == 1)
		sb(stack_b, 0);
	if (order_a == 2 && order_b == 12)
		rr(stack_a, stack_b);
	else if (order_b == 12)
		sb(stack_b, 0);
	if (order_a == 2 && order_b == 2)
		rr(stack_a, stack_b);
	else if (order_a == 2)
		ra(stack_a, 0);
	else if (order_b == 2)
		rb(stack_b, 0);	
	if (order_a == 4 && order_b == 0)
		pb(stack_a, stack_b);
	if (order_a == 3)
		rra(stack_a, 0);*/
}
int find_third_hight_value(t_list **stack_a)
{
    int first;
    int second;
    int third;
    t_list *current;

    first = INT_MIN;
    second = INT_MIN;
    third = INT_MIN;
    current = *stack_a;
    while (current != NULL)
    {
        if (current->value > first)
        {
            third = second;
            second = first;
            first = current->value;
        }
        else if (current->value > second && current->value < first)
        {
            third = second;
            second = current->value;
        }
        else if (current->value > third && current->value < second)
            third = current->value;
        current = current->next;
    }
    //printf("THIRDDDDDDDDD : %i\n", third);
    return (third);
}    
