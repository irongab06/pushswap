#include "push_swap.h"

void	sa(t_list **stack_a, int ss)
{
	if (ft_lstsize(stack_a) <= 1 || stack_a == NULL)
		return ;
	t_list	*first;
	t_list	*second;
	
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

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *temp_a;

    if (*stack_b == NULL)
        return;

    temp_a = *stack_b;
    *stack_b = (*stack_b)->next;

    if (*stack_b != NULL) // Ajout de la vérification pour éviter le segfault
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
		return;
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

void	sb(t_list **stack_b, int ss)
{
	if (ft_lstsize(stack_b) <= 1 || stack_b == NULL)
		return ;
	t_list	*first;
	t_list	*second;
	
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

void	rb(t_list **stack_b, int rr)
{
	if (ft_lstsize(stack_b) <= 1 || stack_b == NULL)
		return;
	t_list	*first;
	t_list	*last;

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
