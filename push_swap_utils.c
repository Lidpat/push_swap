/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:52:48 by lpalacio          #+#    #+#             */
/*   Updated: 2024/03/22 01:20:48 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (args[row])
		row++;
	return (row);
}

int	is_sorted(t_list *lst)
{
	t_list	*aux;
	int		num;

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

void	rotate_a_ntimes(int times, t_list **stack_a)
{
	while (times--)
	{
		rotate (stack_a, "ra\n");
	}
}

void	reverse_a_ntimes(int times, t_list **stack_a)
{
	while (times >= 0)
	{
		reverse(stack_a, "rra\n");
		times--;
	}
}
