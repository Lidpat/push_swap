/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:16:15 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 20:16:42 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*comp;
	unsigned char	cc;

	comp = (unsigned char *)s;
	cc = (unsigned char)c;
	if (n != 0)
	{
		while (n--)
		{
			if (*comp == cc)
				return (comp);
			comp++;
		}
	}
	return (NULL);
}
