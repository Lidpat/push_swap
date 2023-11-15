/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:02:32 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/10 22:20:37 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (del != NULL)
	{
		while (*lst != NULL)
		{
			aux = (*lst)->next;
			del ((*lst)->content);
			free(*lst);
			*lst = aux;
		}
	}
}
