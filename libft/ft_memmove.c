/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:04:12 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 20:32:16 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_buff;
	char		*dst_buff;
	size_t		i;

	i = len;
	dst_buff = (char *)dst;
	src_buff = (const char *)src;
	if (dst_buff == NULL && src_buff == NULL)
		return (NULL);
	else if (len > 0)
	{
		if (dst < src && (dst + len) > src)
		{
			while (len--)
				dst_buff[i - len - 1] = src_buff[i - len - 1];
		}
		else if (dst != src)
		{
			while (len--)
				dst_buff[len] = src_buff[len];
		}
	}	
	return (dst);
}
