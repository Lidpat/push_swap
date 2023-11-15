/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:52:34 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 21:47:53 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen (s);
	if (s == NULL)
		return (NULL);
	if (len == 0 || start >= s_len + 1)
		str = (char *)ft_calloc (1, sizeof(char));
	else if ((len + start) >= s_len)
		str = (char *)ft_strdup (s + start);
	else
	{
		str = (char *)ft_calloc (len + 1, sizeof(char));
		if (str != NULL)
			ft_strlcpy (str, s + start, len + 1);
	}
	return (str);
}
