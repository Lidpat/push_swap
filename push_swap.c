/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 21:08:19 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check_duplicated int
//sortout

t_list	*validate_arg(char **args, t_list **stack_a)
{
	int	j;
	int	**num;
	t_list	*new_node;

	j = count_rows(args);
	num = (int **)ft_calloc(j, sizeof(int *));
	if (num == NULL)
		exit (2);
	j = 0;
	while (args[j])
	{
		is_valid_str_for_int(args[j]);
		num[j] = (int *)ft_calloc(1, sizeof(int));
		if (!num[j])
			exit (22);
		*num[j] = ft_atoi(args[j]);
		free(args[j]);
		new_node = ft_lstnew((void *)num[j]);
		ft_lstadd_back(stack_a, new_node);
		j++;
	}
	free (num);
	return (0);
}

int	check_and_load(char *argv[], t_list **stack_a)
{
	int		 i;
	char	**args;
	
	i = 1;  // arg(0) es el comando de llamada al programa
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (args == NULL)
			exit (1);
		validate_arg(args, stack_a);
		free(args);
		
		//free args // OJO 2D
		i++;		
	}
	return (0);
}

/**

//SORTING MOVES
	//swap(a/b/s)
	//push(a/b)
	//rotate(a/b/r)
	//reverse_rotate(a/b/r)

int push_swap (list stack_a)
{
	//VARS
	//  *int instruction_list (int[]) //integer string mapear valores movimientos (1=sa 2=sa 3=ss 4=ra 5=rb...  10=rrb 11=rrr) 
	
	//
	return (0);
}
*/

#include <stdio.h> // BORRAR
int main (int argc, char *argv[])
{
	t_list	*stack_a;  //OJO Malloc
	t_list	*stack_b;  //OJO Malloc
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		 return (-1);
	
	check_and_load(argv, &stack_a);  //if fails call exit

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
	/*** TEST ROTATE() ***/
	ft_lstiter(stack_a, ft_putnbr_endl);  //print stack_a
	
	printf("rotate 1: %d\n", rotate(&stack_a));
	ft_lstiter(stack_a, ft_putnbr_endl);

	write (1, "-----\n", 6);	

	printf("rotate b: %d\n", rotate(&stack_b));
	ft_lstiter(stack_b, ft_putnbr_endl);
		
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);

	//push_swap(<lista generada en stack_load>)  
		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	//FREE stack_a  stack_b  //free 2D malloc -> variadric
	return (0);
}
