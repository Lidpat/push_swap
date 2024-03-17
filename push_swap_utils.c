/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:52:48 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 21:42:28 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free malloc 2D   //variadric?
//

void	error_and_exit(int n)
{
	ft_putendl_fd("Error", 2);
	write (2, "\n", 1);
	exit (n);
}

int	count_rows(char **args)
{
	int	row;

	row = 0;
	while(args[row])
		row++;
	return (row);
}

int	is_sorted(t_list *lst)
{
	t_list	*aux;
	int	num;  

	aux = lst;
		while (aux != NULL)
		{
			num = ((int *)(aux->content))[position];
			aux = aux->next;
			if (aux != NULL && num > ((int *)(aux->content))[position])
				return (0);
		}
	return (1);
}