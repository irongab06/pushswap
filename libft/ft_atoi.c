/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <gacavali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:59:25 by gacavali          #+#    #+#             */
/*   Updated: 2024/06/10 13:20:47 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long long	ft_atoi(char *str)
{
	long long	i;
	int			count;
	long long	sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && ++count)
			sign = sign * -1;
		if (str[i] == '+')
			count++;
		if (count > 1)
			return (ATOI_ERROR);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	return (number * sign);
}
/*
int	main(void)
{
	printf("%lli\n", ft_atoi("-12345"));
	printf("%i", atoi("12345"));
	return(0);
}*/
