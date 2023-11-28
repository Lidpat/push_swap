/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:29:55 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/30 22:42:35 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*** PROTECTED str NULL ***/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	int		sign;
	int		i;
	int		j;

	if (str == NULL)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	while (i < j)
	{
		num = num * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (num);
}
