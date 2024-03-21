/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:49:59 by lpalacio          #+#    #+#             */
/*   Updated: 2024/03/21 22:30:53 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack, char *str)
{
	t_list	*aux;

	if (!(*stack)->next)
		return (0);
	aux = *stack;
	*stack = aux->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
	ft_putstr_fd(str, 1);
	return (1);
}

int	push(t_list **lst_src, t_list **lst_dst, char *str)
{
	t_list	*node;

	if (!*lst_src)
		return (0);
	node = *lst_src;
	*lst_src = node->next;
	ft_lstadd_front(lst_dst, node);
	ft_putstr_fd(str, 1);
	return (1);
}

int	rotate(t_list **stack, char *str)
{
	t_list	*node;

	if (!*stack || !(*stack)->next)
		return (0);
	node = *stack;
	*stack = node->next;
	node->next = NULL;
	ft_lstadd_back(stack, node);
	ft_putstr_fd(str, 1);
	return (1);
}

int	reverse(t_list **stack, char *str)
{
	t_list	*node;
	t_list	*aux;

	if (!*stack || !(*stack)->next)
		return (0);
	node = ft_lstlast(*stack);
	aux = *stack;
	while (aux->next != node)
		aux = aux->next;
	aux->next = NULL;
	ft_lstadd_front(stack, node);
	ft_putstr_fd(str, 1);
	return (1);
}
