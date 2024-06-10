/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:51:35 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:27:50 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (0);
}

void	check_duplicate(t_list **stack_a)
{
	t_list	*temp;
	t_list	*reset;

	temp = *stack_a;
	while (temp != NULL)
	{
		reset = temp->next;
		while (reset != NULL)
		{
			if (temp->value == reset->value)
			{
				ft_error_lst(stack_a);
			}
			reset = reset->next;
		}
		temp = temp->next;
	}
}

void	check_argv(int argc, char **argv)
{
	char		**all_argv;
	int			i;
	int			j;
	long long	min_max;

	i = 1;
	while (i < argc)
	{
		all_argv = NULL;
		all_argv = ft_split(argv[i], ' ');
		j = 0;
		while (all_argv[j])
		{
			min_max = ft_atoi(all_argv[j]);
			if (ft_strlen(all_argv[j]) > 12 || check_digit(all_argv[j]) == 1)
				ft_error(all_argv);
			if (min_max < INT_MIN || min_max > INT_MAX || min_max == ATOI_ERROR)
				ft_error(all_argv);
			j++;
		}
		i++;
		ft_free(all_argv);
	}
}
