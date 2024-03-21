/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:29:55 by lpalacio          #+#    #+#             */
/*   Updated: 2024/03/21 22:21:34 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*** PROTECTED for push_swap: Check INT overflow ***/

#include "libft.h"

void	error_exit_atoi(int n)
{
	ft_putendl_fd("Error", 2);
	exit (n);
}

int	ft_atoi(const char *str)
{
	long			num;
	int				sign;
	int				i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (sign * (str[i] - '0'));
		i++;
	}
	if (num < INT_MIN || num > INT_MAX)
		error_exit_atoi(4);
	return ((int)num);
}
