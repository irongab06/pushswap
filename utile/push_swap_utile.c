/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:55:09 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/13 15:13:58 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
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
	while (stack_a != NULL && stack_a->next != NULL)
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
	int		i;
	int		j;
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
