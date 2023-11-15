/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:28:29 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/03 21:41:28 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max_size_t;

	max_size_t = (size_t) - 1;
	if (size > 0 && count > max_size_t / size)
		return (NULL);
	ptr = malloc (count * size);
	if (ptr != NULL)
		ft_bzero (ptr, count * size);
	return (ptr);
}
