/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2023/11/16 22:17:09 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
list	load_stack (char *argv)
{
	//split(argv, ' ')  //MALLOC
	//atoi
	//guardar en nodo de lista
	return (0);
}
*/

int	are_digits(char *argv[])
{
	int	i = 1;
	int	j = 0;
	
	while (argv[i])
	{
		while(argv[i][j])
		{
			if(ft_isdigit(argv[i][j]) || argv[i][j] == ' ' || argv[i][j] == '-')
				j++;
			else
			{
				ft_putendl_fd("Error", 2);
				return (-1);
			}
		}
		j = 0;
		//pasar argv[i] a una función atoi + guardar_en formato final (str, posicion, ....) 4o6 líneas de margen BORRAR 
		i++;
	}
	return (0);
}

int	check_parameters(char *argv[])
{
	if(are_digits(argv))
		return(-1);
	return (0);
}

/**
int push_swap (list stack_a)
{
	//VARS
	//  *int instruction_list (int[]) //integer string mapear valores movimientos (1=sa 2=sa 3=ss 4=ra 5=rb...  10=rrb 11=rrr) 
	
	//
	return (0);
}

//SORTING MOVES
	//swap(a/b/s)
	//push(a/b)
	//rotate(a/b/r)
	//reverse_rotate(a/b/r)
*/

int main (int argc, char *argv[])
{
	if (argc == 1)
		 return (-1);
	if (check_parameters(argv))
		return (-1);
		
	//stack_load
	//push_swap(<lista generada en stack_load>)  
		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	return (0);
}
