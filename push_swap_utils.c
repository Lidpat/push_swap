/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:52:48 by lpalacio          #+#    #+#             */
/*   Updated: 2023/11/28 23:06:41 by lpalacio         ###   ########.fr       */
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
		return (0);
	while (str[i])
	{
		if(!ft_isdigit(str[i]))  //Castear? BORRAR
			return (0);
		i++;
	}
	return (1);
}


