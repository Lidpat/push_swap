/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:28:13 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 19:29:41 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	n;

	d = ft_strlen(dst);
	n = 0;
	if (dstsize <= d)
		return (dstsize + ft_strlen(src));
	while ((d + n) < (dstsize - 1) && src[n] != 0)
	{
		dst[d + n] = src[n];
		n++;
	}
	dst[d + n] = 0;
	return (d + ft_strlen(src));
}
