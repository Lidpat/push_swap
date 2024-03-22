/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2024/03/22 20:54:25 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3numb(t_list **stack_a)
{
	t_list	*aux;
	int		num0;
	int		diff;

	aux = *stack_a;
	num0 = ((int *)(aux->content))[position];
	aux = aux->next;
	diff = ((int *)(aux->content))[position] - num0;
	if (diff == 1 || diff == 2)
		reverse(stack_a, "rra\n");
	if (diff == 2)
		swap(stack_a, "sa\n");
	else if (diff == -2)
		rotate (stack_a, "ra\n");
	else if (diff == -1)
	{
		aux = aux->next;
		diff = num0 - ((int *)(aux->content))[position];
		swap(stack_a, "sa\n");
		if (diff == 2)
			reverse(stack_a, "rra\n");
	}
}

int	get_position(int num, t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 1;
	aux = lst;
	while (aux != NULL)
	{
		if (num == ((int *)(aux->content))[position])
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

int	sort_n(t_list **stack_a, t_list *stack_b, int min)
{
	int	position;
	int	lst_size;

	if (ft_lstsize(*stack_a) == 3)
	{
		if (!is_sorted(*stack_a))
			sort_3numb (stack_a);
		push_all_a(&stack_b, stack_a);
		return (1);
	}
	else
	{
		position = get_position(min, *stack_a);
		lst_size = ft_lstsize(*stack_a);
		if (position <= (lst_size / 2 + lst_size % 2))
			rotate_a_ntimes(position - 1, stack_a);
		else
			reverse_a_ntimes(lst_size - position, stack_a);
		push(stack_a, &stack_b, "pb\n");
		return (sort_n(stack_a, stack_b, min + 1));
	}
}

int	push_swap(t_list **stack)
{
	int		stack_size;

	stack_size = ft_lstsize(*stack);
	if (stack_size == 2)
		swap(stack, "sa\n");
	else if (stack_size == 3)
		sort_3numb(stack);
	else if (stack_size <= 35)
		sort_n(stack, NULL, 0);
	else
		radix_sort(stack, stack_size);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stack;
	int		sort;

	stack = NULL;
	if (argc == 1)
		return (-1);
	check_and_load(argv, &stack);
	check_duplicated_and_sort(stack);
	sort = is_sorted(stack);
	if (!sort)
		push_swap(&stack);
	ft_lstclear(&stack, free);
	return (0);
}
