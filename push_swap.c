/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2023/10/31 22:13:20 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	param_control(char *argv[])
{
	
	write(2, "Error\n", 6);
	return (0);
}

int push_swap (list stack_a)
{
	//VARS
	//*int instruction_list (int[]) //integer string mapear valores movimientos (1=sa 2=sa 3=ss 4=ra 5=rb...  10=rrb 11=rrr) 
	
	//
	return (0);
}

//SORTING MOVES
	//swap(a/b/s)
	//push(a/b)
	//rotate(a/b/r)
	//reverse_rotate(a/b/r)

int main (int argc, char *argv[])
{
	if (argc == 1)
		 return (-1);
	param_control(argv);
		
	//param_control
	//stack_load
	//push_swap(<lista generada en stack_load>)  
		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	return (0);
}
