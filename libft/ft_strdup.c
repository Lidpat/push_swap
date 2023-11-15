/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:28 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 21:56:14 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	n;
	size_t	check;

	n = ft_strlen (s1) + 1;
	str = (char *)malloc (n * sizeof(char));
	if (str != NULL)
	{	
		check = ft_strlcpy(str, s1, n);
		if (check >= n)
		{
			free (str);
			return (NULL);
		}
	}
	return (str);
}
