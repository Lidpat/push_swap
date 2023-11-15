/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:08:31 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 20:56:10 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != 0 && (ft_strchr(set, s1[i]) != NULL))
		i++;
	while (j > i && (ft_strchr(set, s1[j]) != NULL))
		j--;
	len = j - i + 1;
	str = ft_substr (s1, i, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
