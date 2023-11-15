/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:20:54 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 20:21:30 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*pos;
	size_t	i;
	size_t	j;

	pos = (char *)haystack;
	i = 0;
	if (*needle == 0)
		return (pos);
	while (i < len && pos[i] != 0)
	{
		if (needle[0] == pos[i])
		{
			j = 0;
			while (needle[j] == pos[i + j] && (i + j) < len && pos[i] != 0)
			{
				j++;
				if (needle[j] == 0)
					return (pos + i);
			}
		}
		i++;
	}
	return (NULL);
}
