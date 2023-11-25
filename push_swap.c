/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2023/11/25 18:20:09 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
list	load_stack (char *argv)
{
	//split(argv, ' ')  //MALLOC
	//atoi
	//add node to list
	return (0);
}
*/

int	is_valid_arg(char *argv)
{
	int	j;
	char	*args;

	j = 0;
	args = ft_split(argv, ' ');
	if (args == NULL);
		return (-1);
	while (args[j])
	{
		if(ft_isdigit(args[j] || args[j] == '+' || args[j] == '-')
			j++;
		else
		{
			ft_putendl_fd("Error", 2);
			free (args); // OJO ¿2D?
			return (-1);
		}
		//num = ft_atoi(args[j]);
		//new_node = ft_lstnew(num);
		//ft_lstadd_back(stack_a, new_node); 
		
	}	
	free (args);  //OJO ¿2D?
	return (0);
}

int	check_and_load(char *argv[], t_list stack_a)
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		if(is_valid_arg(argv[i]))
		{
			//free stack_a
			return(-1);
		}
		i++		

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

int main (int argc, char *argv[])
{
	t_list	*stack_a;  //OJO Malloc
	t_list	*stack_b;  //OJO Malloc

	if (argc == 1)
		 return (-1);
	if (check_and_load(argv, stack_a))
	{
		//FREE stack_a
		return (-1);
	}
	//push_swap(<lista generada en stack_load>)  
		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	//FREE stack_a  stack_b  //free 2D malloc -> variadric
	return (0);
}
