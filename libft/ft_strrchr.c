/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:14:04 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 20:14:44 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = (char *)s + ft_strlen(s);
	while (pos >= s)
	{
		if (*pos == (char)c)
			return (pos);
		pos--;
	}
	return (NULL);
}
