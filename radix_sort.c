/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:58:29 by lpalacio          #+#    #+#             */
/*   Updated: 2024/03/22 20:40:53 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits_number(int lst_size)
{
	if (lst_size <= 2)
		return (1);
	if (lst_size <= 4)
		return (2);
	if (lst_size <= 8)
		return (3);
	if (lst_size <= 16)
		return (4);
	if (lst_size <= 32)
		return (5);
	if (lst_size <= 64)
		return (6);
	if (lst_size <= 128)
		return (7);
	if (lst_size <= 256)
		return (8);
	if (lst_size <= 512)
		return (9);
	if (lst_size <= 1024)
		return (10);
	return (16);
}

void	move_zero_right(t_list **lst_src, t_list **lst_dst, int bit)
{
	int		numb;
	int		bit_value;
	t_list	*aux;
	int		stack_size;

	aux = *lst_src;
	stack_size = ft_lstsize(aux);
	while (stack_size--)
	{
		numb = ((int *)(aux->content))[position];
		bit_value = (numb >> bit) % 2;
		if (bit_value == 0)
			push(lst_src, lst_dst, "pb\n");
		else
			rotate(lst_src, "ra\n");
		aux = *lst_src;
	}
}

void	move_one_left(t_list **lst_src, t_list **lst_dst, int bit)
{
	int		numb;
	int		bit_value;
	t_list	*aux;
	int		stack_size;

	aux = *lst_src;
	stack_size = ft_lstsize(aux);
	while (stack_size--)
	{
		numb = ((int *)(aux->content))[position];
		bit_value = (numb >> bit) % 2;
		if (bit_value == 1)
			push(lst_src, lst_dst, "pa\n");
		else
			rotate(lst_src, "rb\n");
		aux = *lst_src;
	}
}

void	radix_sort(t_list **stack_a, int stack_size)
{
	t_list	*stack_b;
	int		bit;
	int		bit_max;

	stack_b = NULL;
	bit = 0;
	bit_max = get_bits_number(stack_size);
	while (bit < bit_max)
	{
		if (bit == 0)
			move_zero_right(stack_a, &stack_b, bit);
		else
		{
			move_one_left(&stack_b, stack_a, bit);
			move_zero_right(stack_a, &stack_b, bit);
		}
		bit++;
	}
	push_all_a(&stack_b, stack_a);
}
