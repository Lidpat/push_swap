/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:03:29 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/02 22:03:48 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*buff;
	const char	*src_b;

	buff = (char *)dst;
	src_b = (const char *)src;
	if (n > 0 && (dst != 0 || src != 0))
	{	
		while (n--)
			buff[n] = src_b[n];
	}
	return (dst);
}
