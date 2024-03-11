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
	ft_putnbr_fd(n, 2);  // BORRAR
	write (2, "\n", 1);
	exit (n);
}




//print pair of integers in a 2D on a list
void	ft_putnbr_endl(void *num)
{
	ft_putnbr_fd(((int *)(num))[value], 1);
	write(1,"\t",1);
	ft_putnbr_fd(((int *)(num))[position], 1);
	write(1, "\n", 1);
	return ;
}


int	count_rows(char **args)
{
	int	row;

	row = 0;
	while(args[row])
		row++;
	return (row);
}
