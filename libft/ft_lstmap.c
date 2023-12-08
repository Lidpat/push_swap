/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:08:41 by lpalacio          #+#    #+#             */
/*   Updated: 2022/10/14 00:37:45 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	t_list	*node;

	if (lst == NULL || f == NULL)
		return (NULL);
	aux = lst;
	new = ft_lstnew(f(aux->content));
	aux = aux->next;
	while (aux != NULL)
	{
		node = ft_lstnew(f(aux->content));
		if (node == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		aux = aux->next;
	}	
	return (new);
}
