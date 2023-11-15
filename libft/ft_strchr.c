/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:12:50 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 20:33:48 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pos;

	pos = (char *)s;
	while (*pos != 0)
	{
		if (*pos == (char)c)
			return (pos);
		pos++;
	}
	if (*pos == (char)c)
		return (pos);
	return (NULL);
}
