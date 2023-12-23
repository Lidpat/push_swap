/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:49:59 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 20:42:16 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Permute first and second nodes positions*/
/* only if there are more than one element*/

int swap(t_list **stack)
{
    t_list *aux;
     
    //if (ft_lstsize(*stack) < 2)
	if (!(*stack)->next)  
        return (0);
    aux = *stack;  //pointer to A
    *stack = aux->next; // pointer to B 
    aux->next = (*stack)->next; // A points to node B next (nodo 3)
    (*stack)->next = aux; //aux contains pointer to A
    return (1);
}

int	push(t_list **lst_src, t_list **lst_dst)
{
	t_list *node;

	if (!*lst_src)
		return (0);
	node = *lst_src; // pointer to node to move from src to dst
	*lst_src = node->next; // mv 2nd node to 1st position on src lst
	ft_lstadd_front(lst_dst, node); //mv node to 1st posistion of dst lst
	return (1);
}

