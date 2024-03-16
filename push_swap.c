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
		{
			push(lst_src, lst_dst);
			write (1, "pb\n", 3);
		}
		else //if (stack_size > 0)
		{	
			rotate(lst_src);
			write (1, "ra\n", 3);
		}
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
		{
			push(lst_src, lst_dst);
			write (1, "pa\n", 3);
		}
		else //if (stack_size > 0)
		{
			rotate(lst_src);
			write (1, "rb\n", 3);
		}
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
		push(lst_src, lst_dst);
		write (1, "pa\n", 3);
	}
}

int	push_swap (t_list *stack)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int 	bit;
//	int		bit_value;
	int		bit_max;
	int		stack_size;
//	int		numb;
	

	stack_a = stack;
	stack_b = NULL;
	bit = 0;
	stack_size = ft_lstsize(stack);
	bit_max = get_bits_number(stack_size);
	//while (bit < bit_max)
	//	ft_lstiter(stack_a, ft_putnbr_endl);
	//write (1, "\n", 1);
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

	// 	write (1, "* Stack_A\n", 10);
	// ft_lstiter(stack_a, ft_putnbr_endl);
	// write (1, "\n", 1);
	// write (1, "* Stack_B\n", 10);
	// ft_lstiter(stack_b, ft_putnbr_endl);

	//VARS
	//  *int instruction_list (int[]) //integer string mapear valores movimientos (1=sa 2=sa 3=ss 4=ra 5=rb...  10=rrb 11=rrr) 
	return (0);
	
}

#include <stdio.h> // BORRAR
int main (int argc, char *argv[])
{
	t_list	*stack;  //OJO Malloc
	//t_list	*stack_b;  //OJO Malloc
	int sort;

	stack = NULL;
	//stack_b = NULL;
	if (argc == 1)
		 return (-1);
	else if (argc == 2)
		return(0);
	
	check_and_load(argv, &stack);  //if fails call exit
	check_duplicated_and_sort(stack);
	sort = is_sorted(stack);
	if (sort)
		printf("stack entrada ordenado\n");
	else
		printf ("stack entrada Desordenado\n"); 	
	push_swap(stack);

/************ TESTS BLOCK *******************************************************************/

/*** TEST SWAP() ***/
/*	ft_lstiter(stack_a, ft_putnbr_endl);  //print stack_a
	printf("swap: %d\n", swap(&stack_a));
	ft_lstiter(stack_a, ft_putnbr_endl);
	ft_lstclear(&stack_a, free);  //free stack_a
*/

	/*** TEST PUSH() ***/
/*	ft_lstiter(stack_a, ft_putnbr_endl);  //print stack_a
	write (1, "\n", 1); 
	ft_lstiter(stack_b, ft_putnbr_endl);  //print stack_b
	
	printf("push 1: %d\n", push(&stack_b, &stack_a));
	ft_lstiter(stack_a, ft_putnbr_endl);
	write (1, "\n", 1);
	ft_lstiter(stack_b, ft_putnbr_endl);  //print stack_b

	write (1, "-----\n", 6);	

	printf("push 2: %d\n", push(&stack_a, &stack_b));
	ft_lstiter(stack_a, ft_putnbr_endl);
	write (1, "\n", 1);
	ft_lstiter(stack_b, ft_putnbr_endl);  //print stack_b
*/
	/*** TEST ROTATE() o REVERSE() ***/
/*
	ft_lstiter(stack_a, ft_putnbr_endl);  //print stack_a
	
	printf("rotate 1: %d\n", reverse(&stack_a));
	ft_lstiter(stack_a, ft_putnbr_endl);

	write (1, "-----\n", 6);	

	printf("rotate b: %d\n", reverse(&stack_b));
	ft_lstiter(stack_b, ft_putnbr_endl);
		
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
*/	
//	write (1, "- - -- - -\n", 11);
//	ft_lstiter(stack, ft_putnbr_endl);  //print stack_a
	
/************ Fin Test Block *******************************************************************/

	//push_swap(<lista generada en stack_load>)  
		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	//FREE stack_a  stack_b  //free 2D malloc -> variadric
	return (0);
}
