#include "push_swap.h"
#include <stdio.h>

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	ft_error_lst(t_list **stack_a)
{
	t_list	*temp;
	t_list	*reset;
	
	reset = *stack_a;
	while (reset != NULL)
	{
		temp = reset;
		reset = reset->next;
		free(temp);
	}
	write(1, "Error", 5);
	write(1, "\n", 1);
	exit (1);
	return (1);
}

int	ft_error(char **str)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
	ft_free(str);
	exit (1);
	return (1);
}
int	stack_in_order(t_list *stack_a)
{
	while(stack_a != NULL && stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
void	init_stack(t_list **stack_a, char **argv)
{
	char	**temp_argv;
	int	i;
	int	j;
	t_list	*node;

	temp_argv = NULL;
	i = 0;
	while (argv[i])
	{
		j = 0;
		temp_argv = NULL;
		temp_argv = ft_split(argv[i], ' ');
		while (temp_argv[j])
		{	
			node = ft_lstnew_int(ft_atoi(temp_argv[j]));
			ft_lstadd_back(stack_a, node);
			j++;
		}
		i++;
		ft_free(temp_argv);
	}
}
void	algo_dispatcher(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) <= 2)
		sort_for_2(stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_for_3(stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_for_5(stack_a, stack_b);
	else if (ft_lstsize(stack_a) > 5)
		sort_with_nolimit(stack_a, stack_b);
}

int	find_min(t_list **stack_a)
{
	t_list	*temp;
	int	value_min;
	
	temp = NULL;	
	if (*stack_a == NULL)
		return (0);
	temp = *stack_a;
	value_min = temp->value;
	while (temp->next != NULL)
	{
		if(temp->next->value < value_min)
		{
			value_min = temp->next->value;
		}
		temp = temp->next;
	}
	return (value_min);

}	
int	find_max(t_list **stack_a)
{
	t_list	*temp;
	int	value_max;

	temp = *stack_a;
	if (temp == NULL)
		return (0);
	value_max = temp->value;
	while (temp->next != NULL)
	{
		if(temp->next->value > value_max)
		{
			value_max = temp->next->value;
		}
		temp = temp->next;
	}
	return (value_max);
}
