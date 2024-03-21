/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 21:44:08 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits_number(int	lst_size)
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
	int stack_size;

	aux = *lst_src;
	stack_size = ft_lstsize(aux);
	while (stack_size--)
	{
		numb = ((int *)(aux->content))[position];
		bit_value = (numb >> bit) % 2;
		if (bit_value == 0)
			push(lst_src, lst_dst, "pb\n");
		else //if (stack_size > 0)
			rotate(lst_src, "ra\n");

//		ft_putnbr_fd (numb, 1);
//		write (1, "\t", 1);
//		ft_putnbr_fd (bit_value, 1);
//		write (1, "\n", 1);
		//aux = aux->next;
		aux = *lst_src; 
	}
	
}

void	move_one_left(t_list **lst_src, t_list **lst_dst, int bit)
{
	int		numb;
	int		bit_value;
	t_list	*aux;
	int stack_size;

	aux = *lst_src;
	stack_size = ft_lstsize(aux);
	while (stack_size--)
	{
		numb = ((int *)(aux->content))[position];
		bit_value = (numb >> bit) % 2;
		if (bit_value == 1)
			push(lst_src, lst_dst, "pa\n");
		else //if (stack_size > 0)
			rotate(lst_src, "rb\n");

//		ft_putnbr_fd (numb, 1);
//		write (1, "\t", 1);
//		ft_putnbr_fd (bit_value, 1);
//		write (1, "\n", 1);
		//aux = aux->next;
		aux = *lst_src; 
	}
}

void	move_all_b(t_list **lst_src, t_list **lst_dst)
{
	int	stack_size;

	stack_size = ft_lstsize(*lst_src);
	while (stack_size--)
	{
		push(lst_src, lst_dst, "pa\n");
	}
}

void	radix_sort(t_list *stack_a, int stack_size)
{
	t_list	*stack_b;
	int		bit;
	int		bit_max;

	stack_b = NULL;
	bit = 0;
	bit_max = get_bits_number(stack_size);
	while(bit < bit_max)
	{
		if (bit == 0)
			move_zero_right(&stack_a, &stack_b, bit);
		else
		{
			move_one_left(&stack_b, &stack_a, bit);
			move_zero_right(&stack_a, &stack_b, bit);
		}
		bit++;
	}
	move_all_b(&stack_b, &stack_a);
}

void	sort_3numb(t_list *stack_a)
{
	t_list	*aux;
	int	num0;
	int diff;  

	aux = stack_a;
	num0 = ((int *)(aux->content))[position];
	aux = aux->next;
	diff = ((int *)(aux->content))[position] - num0;
	if (diff == 1)
		reverse(&stack_a, "rra\n");
	else if (diff == -2)
		rotate (&stack_a, "ra\n");
	else if (diff == -1)
	{
		aux = aux->next;
		diff = num0 - ((int *)(aux->content))[position];
		if (diff == -1)
			swap(&stack_a, "sa\n");
		else if (diff == 2)
		{
			swap(&stack_a, "sa\n");
			reverse(&stack_a, "rra\n");
		}
		else
			ft_putstr_fd("whaat?!?!!", 1); 

	}
	else if (diff == 2)
	{
		aux = aux->next;
		diff = num0 - ((int *)(aux->content))[position];
		if (diff == -1)
		{
			reverse(&stack_a, "rra\n");
			swap(&stack_a, "sa\n");
		}
		else
			ft_putstr_fd("whaat?!?!!", 1); 

	}
	
}

int	get_position(int num, t_list *lst)
{
	int	i;
	t_list *aux; 

	i = 1; 
	aux = lst; 
	while(aux != NULL)
	{
		if (num == ((int *)(aux->content))[position])
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}
void	sort_5numb(t_list *stack_a)
{
	t_list	*stack_b;
	t_list *aux;
	int		pos_0;
	int		pos_1; 

	stack_b = NULL;
	aux = stack_a;
	pos_0 = get_position(0, stack_a);
	pos_1 = get_position(1, stack_a); 
/*	ft_putstr_fd("pos 0: ", 1);
	ft_putnbr_fd(pos_0, 1);
	write (1, "\n", 1);   
		ft_putstr_fd("pos 1: ", 1);
	ft_putnbr_fd(pos_1, 1);
	write (1, "\n", 1);
*/
	if (pos_0 == 1)
	{
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 == 3 || pos_1 == 4)
			rotate (&stack_a, "ra\n");
		if (pos_1 == 4)
			rotate (&stack_a, "ra\n");
		if (pos_1 == 5)
			reverse(&stack_a, "rra\n");
		push(&stack_a, &stack_b, "pb\n");

	}
	else if (pos_0 == 2)
	{
		if(pos_1 == 1)
			swap(&stack_a, "sa\n");
		else
			rotate (&stack_a, "ra\n");
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 == 4 || pos_1 == 5)
			rotate (&stack_a, "ra\n");
		if (pos_1 == 5)
			rotate (&stack_a, "ra\n");
		push(&stack_a, &stack_b, "pb\n");
	}
	else if (pos_0 == 3)
	{
		if (pos_1 != 1)
			rotate (&stack_a, "ra\n");
		if (pos_1 == 4 || pos_1 == 5)
			rotate (&stack_a, "ra\n");
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 ==1 || pos_1 == 5)
			rotate (&stack_a, "ra\n");
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 == 1 || pos_1 == 2)
			swap(&stack_b, "sb\n");
		
	}
	else if (pos_0 == 4)
	{
		if (pos_1 == 1 || pos_1 == 5)
		{
			reverse(&stack_a, "rra\n");
			reverse(&stack_a, "rra\n");
		}
		else
			rotate (&stack_a, "ra\n");
		if (pos_1 == 3)
			rotate (&stack_a, "ra\n");
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 == 1 || pos_1 == 2)
			rotate (&stack_a, "ra\n");
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 == 2 || pos_1 == 3)
			swap(&stack_b, "sb\n");
	}
	else
	{
		reverse(&stack_a, "rra\n");
		push(&stack_a, &stack_b, "pb\n");
		if (pos_1 == 2 || pos_1 == 3)
			rotate (&stack_a, "ra\n");
		if (pos_1 == 3)
			rotate (&stack_a, "ra\n");
		else if (pos_1 == 4)
			reverse(&stack_a, "rra\n");
		push(&stack_a, &stack_b, "pb\n");

	}
	if (!is_sorted(stack_a))
		sort_3numb (stack_a);
	move_all_b(&stack_b, &stack_a);
}

int	push_swap (t_list *stack)
{
	int		stack_size;
	
	stack_size = ft_lstsize(stack);
	if (stack_size == 2)
		swap(&stack, "sa\n"); 
	else if (stack_size == 3)
		sort_3numb(stack);
	else if (stack_size == 5)
		sort_5numb(stack);
	else
		radix_sort(stack, stack_size);

	return (0);
	
}

int main (int argc, char *argv[])
{
	t_list	*stack;
	int sort;

	stack = NULL;
	if (argc == 1)
		 return (-1);

	check_and_load(argv, &stack);
	check_duplicated_and_sort(stack);
	sort = is_sorted(stack);
	if (!sort)
		push_swap(stack);
	ft_lstclear(&stack, free);

		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	return (0);
}
