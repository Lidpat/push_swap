/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:52:48 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/06 23:35:26 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//free malloc 2D   //variadric?
//

void	error_and_exit(int n)
{
	ft_putendl_fd("Error", 2);
	exit (n);
}


/* Check if string has valid length and characters to be an integer */
int	is_valid_str_for_int(char *str)
{
	int i;
	
	i = 0;
	if (str[i] º== '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	if ((ft_strlen(str) - i) > 10)
		error_and_exit(1);;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))  //Castear? BORRAR
			error_and_exit(1);
		i++;
	}
	return (1);
}

void	ft_putnbr_endl(int n)
{
	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
	return ;
}
