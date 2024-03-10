/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:59:36 by lpalacio          #+#    #+#             */
/*   Updated: 2024/01/02 21:06:36 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_max_and_equal(t_list *lst, int *max)
{
	t_list	*aux2;

	aux2 = lst;
	if (max[value] == ((int *)(aux2->content))[value])
		error_and_exit(6);
	if (max[value] < ((int *)(aux2->content))[value])
		return (aux2->content);
	return (max);
}


int		check_duplicated_and_sort(t_list *stack)
{
	t_list	*aux;
	t_list	*aux2;
	int		count;
	int		*max;

	aux = stack;
	count = ft_lstsize(stack);
	while(count)
	{
		max = aux->content;
		if (max[position] == 0)
		{
			aux2 = aux->next; 
			while(aux2)
			{
				if (((int *)(aux2->content))[position] == 0)
					max = check_max_and_equal(aux2, max);
//				{
//					if (max[value] == ((int *)(aux2->content))[value])
//						error_and_exit(6);
//					if (max[value] < ((int *)(aux2->content))[value])
//						max = aux2->content;
//				}
				aux2 = aux2->next;
			}	
			max[position] = count;
			count--;
		}
		else
			aux = aux->next;
	}
return (1); // solo para test
}

