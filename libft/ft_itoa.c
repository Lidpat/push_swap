/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:57:59 by lpalacio          #+#    #+#             */
/*   Updated: 2022/09/30 12:07:54 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	mem_size(int const n)
{
	unsigned int	count;
	int				aux;

	count = 1;
	aux = n;
	if (n <= 0)
		count++;
	while (aux != 0)
	{
		count++;
		aux = aux / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	count;

	count = mem_size (n);
	s = (char *)ft_calloc (count, sizeof(char));
	if (s == NULL)
		return (NULL);
	count--;
	s[count] = 0;
	while (count-- > 0)
	{
		if (n < 0)
			s[count] = '0' - n % 10;
		else
			s[count] = '0' + n % 10;
		n = n / 10;
		if (n == 0 && count == 1)
		{
			s[0] = '-';
			count--;
		}	
	}
	return (s);
}
