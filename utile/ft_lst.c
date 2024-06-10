/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:48:50 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 14:24:38 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew_int(long long value)
{
	t_list	*node;

	node = NULL;
	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
	new->prev = temp;
}

int	ft_lstsize(t_list **stack_a)
{
	int		i;
	t_list	*temp;

	temp = *stack_a;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_last_value(t_list **stack_a)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	while (temp_a->next != NULL)
	{
		temp_a = temp_a->next;
	}
	return (temp_a->value);
}
